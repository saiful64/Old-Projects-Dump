package Connect4;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class Main extends Application {


    private Controller controller;

    @Override
    public void start(Stage primaryStage) throws Exception{

        FXMLLoader loader = new FXMLLoader(getClass().getResource("game.fxml"));
        GridPane rootGridPane = loader.load();

        controller = loader.getController();
        controller.createPlayground();

        MenuBar menuBar = createMenu();
        menuBar.prefWidthProperty().bind(primaryStage.widthProperty());

        Pane menuPane = (Pane) rootGridPane.getChildren().get(0);
        menuPane.getChildren().add(menuBar);

        Scene scene = new Scene(rootGridPane);

        primaryStage.setScene(scene);
        primaryStage.setTitle("Connect4");
        primaryStage.setResizable(false);
        primaryStage.show();
    }

    private MenuBar createMenu() {
        //File Menu
        Menu fileMenu = new Menu("File");

        MenuItem newGame = new MenuItem("New Game");
        newGame.setOnAction(event -> controller.resetGame());

        MenuItem resetGame = new MenuItem("Reset Item");
        resetGame.setOnAction(event -> controller.resetGame());

        MenuItem exitGame = new MenuItem("Exit Item");
        exitGame.setOnAction(event -> exitGame());

        fileMenu.getItems().addAll(newGame,resetGame,exitGame);

        //Help Menu
        Menu helpMenu = new Menu("Help");
        MenuItem aboutApp = new MenuItem("About App");
        aboutApp.setOnAction(event -> aboutApp());

        MenuItem aboutDeveloper = new MenuItem("About Developer");
        aboutDeveloper.setOnAction(event -> aboutDeveloper());

        helpMenu.getItems().addAll(aboutApp,aboutDeveloper);

        MenuBar menuBar = new MenuBar();
        menuBar.getMenus().addAll(fileMenu,helpMenu);

        return menuBar;

    }

    private void aboutDeveloper() {

        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("About Developer");
        alert.setHeaderText("SAIFUL ISLAM");
        alert.setContentText("A wanderer, student, love to code and play PC games."+
                "\nOne of them is Connect4");
        alert.show();
    }

    private void aboutApp() {

        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("About Connect4");
        alert.setHeaderText("How to Play?");
        alert.setContentText("Connect4 is a 2 - player game in which the "+
                "player has to choose a colour and then take turn dropping coloured disks"+
                "from top into a 7-column, 6-row vertically suspended grid."+
                "The pieces fall straight down, occupying the next available space within the column." +
                "The objective of the game is to be the first to form a horizontal, vertical, or diagonal line "+
                "of four of one's own discs. Connect4 is a solved game."+
                "\nTips - 'Play the first move with right moves and win the game.'"+
                "\nHappy Playing!");
        alert.show();
    }

    private void exitGame() {

        Platform.exit(); //Close Application
        System.exit(0); // ShutDown resources ex. threads
    }


    public static void main(String[] args) {
        launch(args);
    }
}
