const express = require("express");
const bodyParser = require("body-parser");
const request = require("request");

const app = express();

app.use(express.static("public"));
app.use(bodyParser.urlencoded({
  extended: true
}));

app.get("/", function(req, res) {
  res.sendFile(__dirname + "/signup.html")
});

app.post("/", function(req, res) {
  var fName = req.body.fName;
  var lName = req.body.lName;
  var email = req.body.email;

  var data = {
    members: [
      {
        email_address: email,
        status: "subscribed"
      }
    ]
  };

  var jsonData = JSON.stringify(data)

  var options = {
    url: "https://us8.api.mailchump.com/3.0/lists/98b1912cc6",
    method: "POST",
    headers: {
      "Authorization": "saiful1 d5b56ff8c68c2c2ab224b29da3ed3612-us8"
    },
    body: jsonData
  }

  request(options, function(error, response, body) {
    if(error) {
      console.log(error);
    } else {
      console.log(response.statusCode);
    }
  });

});

app.listen(3000, function() {
  console.log("Server is running on port 3000");
});

//d5b56ff8c68c2c2ab224b29da3ed3612-us8


//98b1912cc6
