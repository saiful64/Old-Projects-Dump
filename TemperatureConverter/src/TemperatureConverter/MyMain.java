package TemperatureConverter;

import javafx.application.Application;

import javafx.application.Platform;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.util.Optional;

public class MyMain extends Application {

    public static void main(String args[]){
        launch(args);
    }
    @Override
    public void start(Stage primaryStage) throws Exception {

        FXMLLoader loader = new FXMLLoader(getClass().getResource("app_layout.fxml")) ;
        VBox rootNode = loader.load();

//        MenuBar menuBar = createMenu();
//        rootNode.getChildren().add(0, menuBar);

        Scene scene = new Scene(rootNode);

        primaryStage.setScene(scene);
        primaryStage.setTitle("TempConverter");
        primaryStage.setResizable(false);
        primaryStage.show();

    }
    private MenuBar createMenu(){
        // File Menu
        Menu fileMenu = new Menu("File");
        MenuItem newMenuItem= new Menu("New");

        newMenuItem.setOnAction(event -> {

        });

        SeparatorMenuItem separatorMenuItem = new SeparatorMenuItem();
        MenuItem quitMenuItem = new Menu("Quit");

        quitMenuItem.setOnAction(event -> Platform.exit());

        fileMenu.getItems().addAll(newMenuItem,separatorMenuItem,quitMenuItem);

        //Help Menu
        Menu helpMenu = new Menu("Help");
        MenuItem aboutApp = new Menu("About");

        aboutApp.setOnAction(event -> aboutApp());

        helpMenu.getItems().addAll(aboutApp);

        //Menu Bar
        MenuBar menuBar = new MenuBar();

        menuBar.getMenus().addAll(helpMenu);
        return menuBar;

    }

    private void aboutApp() {
        Alert alertDialog= new Alert(Alert.AlertType.INFORMATION);
        alertDialog.setTitle("Temp Converter Tool");
        alertDialog.setHeaderText("About app");
        alertDialog.setContentText("This app is copyright by SAIFUL ISLAM, A useful tool to convert the temperature");

        ButtonType yesBtn = new ButtonType("Yes");
        ButtonType noBtn = new ButtonType("No");

        alertDialog.getButtonTypes().setAll(yesBtn,noBtn);

        Optional<ButtonType> clickBtn = alertDialog.showAndWait();

        if( clickBtn.isPresent() && clickBtn.get() == yesBtn) {
            System.out.print("Yes clicked");
        }

        else {
             System.out.print("No clicked");
        }

    }
}
