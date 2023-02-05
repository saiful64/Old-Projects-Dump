package Connect4;

import javafx.animation.TranslateTransition;
import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.geometry.Point2D;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.Shape;
import javafx.util.Duration;

import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.ResourceBundle;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Controller implements Initializable {

    private static final int COLMN =7;
    private static final int ROW=6;
    private static final int CIRCLR_DIA=80;
    private static final String COLOR1= "#24303E";
    private static final String COLOR2= "#FF69B4";


    private static String P1= "Player 1";
    private static String P2= "Player 2";

    private boolean isP1Turn =true;

    private Disc[][] insertedDiscArray = new Disc[ROW][COLMN]; //For Structural change (for DEVELOPERS)

    @FXML
    public GridPane rootGridPane;
    @FXML
    public Pane insertedDiskPane;
    @FXML
    public Label playerNameLabel;

    private boolean isAllowedToInsert = true; //Flag to avoid multiple addition of same player.

    public void createPlayground() {

        Shape rectWithHoles = createGameUI();
        rootGridPane.add(rectWithHoles,0,1);

        List<Rectangle> rectangleList = createClickColumn();

        for (Rectangle rectangle: rectangleList) {
            rootGridPane.add(rectangle,0,1);
        }

    }

    private Shape createGameUI() {

        Shape rectWithHoles = new Rectangle((COLMN + 1) * CIRCLR_DIA , (ROW + 1) * CIRCLR_DIA );

        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COLMN; j++) {
                Circle circle = new Circle();
                circle.setRadius(CIRCLR_DIA / 2);
                circle.setCenterX(CIRCLR_DIA / 2);
                circle.setCenterY(CIRCLR_DIA / 2);
                circle.setSmooth(true);

                circle.setTranslateX(j * (CIRCLR_DIA + 5) + 20);
                circle.setTranslateY(i * (CIRCLR_DIA + 5) + 25);

                rectWithHoles = Shape.subtract(rectWithHoles, circle);

            }
        }

        rectWithHoles.setFill(Color.WHITE);

        return rectWithHoles;

    }

    private List<Rectangle> createClickColumn() {

        List<Rectangle> rectangleList = new ArrayList<>();

        for(int i = 0; i <COLMN; i++) {
            Rectangle rectangle = new Rectangle(CIRCLR_DIA,(ROW + 1) * CIRCLR_DIA  );
            rectangle.setFill(Color.TRANSPARENT);
            rectangle.setTranslateX(i * (CIRCLR_DIA + 5) + 20);

            rectangle.setOnMouseEntered(event -> rectangle.setFill(Color.valueOf("#eeeeee26")));
            rectangle.setOnMouseExited(event -> rectangle.setFill(Color.TRANSPARENT));

            final int col = i;
            rectangle.setOnMouseClicked(event -> {
                if (isAllowedToInsert) {
                    isAllowedToInsert = false;          //When disc is being dropped no more disc inserted
                    insertDisc(new Disc(isP1Turn), col);
                }
            });

            rectangleList.add(rectangle);
        }


        return rectangleList;
    }

    private void insertDisc(Disc disc, int col) {

        int row = ROW - 1;
        while (row >= 0) {
            if (getDiscIfPresent(row, col) == null)
                break;

            row--;
        }

        if(row < 0) //If it is full, we cannot insert anymore disc
        return;

        insertedDiscArray[row][col] = disc; //For Structural change (for DEVELOPERS)
        insertedDiskPane.getChildren().add(disc); //For Visual Changes (for PLAYERS)

        disc.setTranslateX(col * (CIRCLR_DIA + 5) + 20);
        TranslateTransition translateTransition = new TranslateTransition(Duration.seconds(0.5),disc);

        int currentRow = row;
        translateTransition.setToY(row * (CIRCLR_DIA + 5) + 25);
        translateTransition.setOnFinished(event -> {

            isAllowedToInsert = true; //Finally after disc transition enter next player.

            if (gameEnded(currentRow,col)) {
                gameOver();
                return;
                
            }

            isP1Turn = !isP1Turn;

            playerNameLabel.setText(isP1Turn? P1 : P2);
        });

        translateTransition.play();

    }



    private boolean gameEnded(int row, int col) {

        //Vertical Points.

        List<Point2D> verticalPoints = IntStream.rangeClosed(row - 3, row + 3)              //Range of row values : 0-5
                                         .mapToObj(r -> new Point2D(r, col))    // 0 3,1 3,2 3,3 3,4 3,5 3 ->Point2D
                                         .collect(Collectors.toList());

        //Vertical Points
        List<Point2D> horizontalPoints = IntStream.rangeClosed(col - 3, col + 3)
                .mapToObj(c -> new Point2D(row, c))
                .collect(Collectors.toList());

        //Diagonal 1 Points

        Point2D startPoint1 = new Point2D(row - 3, col + 3);
        List<Point2D> d1Points = IntStream.rangeClosed(0, 6)
                .mapToObj(i -> startPoint1.add(i, -i))
                .collect(Collectors.toList());


        //Diagonal 2 Points

        Point2D startPoint2 = new Point2D(row - 3, col - 3);
        List<Point2D> d2Points = IntStream.rangeClosed(0, 6)
                .mapToObj(i -> startPoint2.add(i, i))
                .collect(Collectors.toList());



        boolean isEnded = checkCombinations(verticalPoints) || checkCombinations(horizontalPoints) || checkCombinations(d1Points) || checkCombinations(d2Points);

        return isEnded;
    }

    private boolean checkCombinations(List<Point2D> points) {

        int chain = 0;

        for (Point2D point: points) {

            int rowIndexForArray = (int) point.getX();
            int colIndexForArray = (int) point.getY();

            Disc disc = getDiscIfPresent(rowIndexForArray,colIndexForArray);

            if (disc != null && disc.isP1Move == isP1Turn) { //If last inserted disk belong to the current player.

                chain++;
                if (chain == 4)
                    return  true;

            }else {
                chain = 0;
            }

        }
        return false;
    }

    private Disc getDiscIfPresent(int row, int col) {  //To prevent ArrayIndexOutOfBoundException

        if (row >= ROW || row < 0 || col >= COLMN || col <0)
            return null;
        return insertedDiscArray[row][col];

    }

    private void gameOver() {

        String winner = isP1Turn ? P1 : P2;
        System.out.print("Winner: " + winner);

        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Connect4");
        alert.setHeaderText("CONGRATULATION " + winner + "you win.");
        alert.setContentText("Want to play again?");

        ButtonType yesBtn = new ButtonType("Yes");
        ButtonType noBtn = new ButtonType("No, Exit");
        alert.getButtonTypes().setAll(yesBtn, noBtn);

        Platform.runLater( () -> {

            Optional<ButtonType> btnClicked = alert.showAndWait();
            if (btnClicked.isPresent() && btnClicked.get() == yesBtn) {
                resetGame();
            } else {
                Platform.exit();
                System.exit(0);
            }
        });
    }

    public void resetGame() {
        insertedDiskPane.getChildren().clear(); //Remove all inserted disk from Pane

        for (int row = 0; row < insertedDiscArray.length; row++) {          // Structurally remove all elements
            for (int col = 0; col < insertedDiscArray[row].length; col++) {
                insertedDiscArray[row][col] = null;
            }
        }

        isP1Turn = true; //Let Player start the game
        playerNameLabel.setText(P1);

        createPlayground(); //Prepare fresh playground.
    }


    private static class Disc extends Circle {

        private final boolean isP1Move;

        public Disc(boolean isP1Move) {

            this.isP1Move = isP1Move;
            setRadius(CIRCLR_DIA / 2);
            setFill(isP1Move? Color.valueOf(COLOR1) : Color.valueOf(COLOR2));
            setCenterX(CIRCLR_DIA / 2);
            setCenterY(CIRCLR_DIA / 2);
        }

    }

    @Override
    public void initialize(URL location, ResourceBundle resources) {



    }
}
