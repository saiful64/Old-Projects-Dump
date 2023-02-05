$("h1").addClass("big-title margin-50");

$("input").keypress( function() {
  $("h1").text(event.key);
});

$("button").on("click", function() {
  $("h1").fadeToggle();
});
