InitWebSocket()

function InitWebSocket() {
    websock = new WebSocket('ws://192.168.43.108:81/');
    websock.onmessage = function (enent) {

        if (event.data = "Connected") {
            document.getElementById("indicator").style.backgroundColor = "#55df55"
        }
        else if (event.data = "Disconnected") {
            document.getElementById("indicator").style.backgroundColor = "red"
        } else {

        }
        let websocket_data = event.data.split(" ")

        switch (websocket_data[0]) {
            case "oscilloscope":
                pushValueChart(websocket_data[1])
                break;
            case "fft":
                updateBar(websocket_data[1], websocket_data[2])
                break;

            default:
                // console.log("hello");
                break;
        }

    }
}
