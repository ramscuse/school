$("document").ready(() => {
    $("#turkey-button").click(() => {
        $("#description").load("description.html #turkey");
        $("#image").load("description.html #turkeypic");
    });
    $("#ham-button").click(() => {
        $("#description").load("description.html #ham");
        $("#image").load("description.html #hampic");
    });
    $("#steak-button").click(() => {
        $("#description").load("description.html #steak");
        $("#image").load("description.html #steakpic");
    });
});