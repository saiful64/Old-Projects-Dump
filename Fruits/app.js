const mongoose = require('mongoose');

mongoose.connect("mongodb://localhost:27017/personsDB", {
  useNewUrlParser: true,
  useUnifiedTopology: true
});

const personsSchema = new mongoose.Schema({
  name: {
    type : String,
    required: true
  },
  age: Number
});

const Person = mongoose.model("Person", personsSchema);

const person = new Person({
  age: 21
});

person.save();
