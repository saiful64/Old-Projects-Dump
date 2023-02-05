var randNum1 = Math.floor(Math.random()*6 + 1);
var randImg1 = "images/dice" + randNum1 + ".png";

document.querySelectorAll("img")[0].setAttribute("src", randImg1);

var randNum2 = Math.floor(Math.random()*6 + 1);
var randImg2 = "images/dice" + randNum2 + ".png";

document.querySelectorAll("img")[1].setAttribute("src", randImg2);


if (randNum1 > randNum2)
{
  document.querySelector("h1").innerHTML = "Player 1 wins!!!";
} else if (randNum1 > randNum2){
  document.querySelector("h1").innerHTML = "Player 2 wins!!!";
} else {
  document.querySelector("h1").innerHTML = "Draw!!!";
}
