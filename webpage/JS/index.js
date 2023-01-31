let DFT_button = false;

function colorChange(e) {
    if (e.classList.toggle("GPIO_ON")) {
        websock.send(`${e.id} : ON_`);
    } else {
        websock.send(`${e.id} : OFF`);
    }
}
// route function for routing
function route(e) {
    e.classList.toggle("ROUTE_ON")
    document.querySelector(`.${e.id}`).classList.toggle("show")
}

function DFT() {
    document.getElementById("myChart").classList.toggle("show");
}



