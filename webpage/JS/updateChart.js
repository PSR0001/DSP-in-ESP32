function updateBar(data, position) {
    if (position <= 15) {
        myBar.data.datasets[0].data[position] = data
        myBar.update();
    }
}

let time = 0;
function pushValueChart(data) {
    let sameData;
    if (data != sameData) {

        myChart.data.datasets[0].data.push(data)
        myChart.data.datasets[0].data.shift()
        sameData = data;
        time += 1
        myChart.data.labels.push(time)
        myChart.data.labels.shift()
        myChart.update();
    }

}

function amplitudeChange(value) {

    let Frequency_value = document.getElementById('Frequency').value
    for (let index = 0; index < Frequency_value; index++) {
        if (index % 2 === 0) {
        } else {
            system_function.data.datasets[0].data[index] = value / 100
        }
    }
    // system_function.data.datasets[0].data[3] = value/100
    system_function.update()
}
function frequencyChange(value) {

    let Amplitude_Value = document.getElementById('Amplitude').value / 100
    let number_array_labels = [];
    let number_array_data = [];

    for (let index = 0; index < value; index++) {
        number_array_labels.push(index)

        if (index % 2 === 0) {
            number_array_data.push(0)
        } else {
            number_array_data.push(Amplitude_Value)

        }
    }
    system_function.data.datasets[0].data = number_array_data
    system_function.data.labels = number_array_labels
    system_function.update()
}
function Zoom() {
    if (system_function.data.labels.length >= 10) {
        system_function.data.labels.splice(0, 10)
        system_function.update()
    }
}
function updateGraph() {
    switch (document.getElementById('functionSelect').value) {
        case '1':
            system_function.data.datasets[0].tension = 0
            system_function.data.datasets[0].stepped = false
            system_function.update()
            break;
        case '2':

            console.log("Two")
            break;
        case '3':
            system_function.data.datasets[0].data = [0, 3.3, 0, 3.3, 0]
            system_function.data.labels = [1, 2, 3, 4, 5]
            system_function.data.datasets[0].stepped = true
            system_function.update()
            break;
        default:
            system_function.data.datasets[0].data = [0, 3.3, 0, 3.3, 0]
            system_function.data.labels = [1, 2, 3, 4, 5]
            system_function.data.datasets[0].tension = 0.5
            system_function.data.datasets[0].stepped = false
            system_function.update()
            break;
    }
}
function resetGraph() {
    system_function.data.datasets[0].data = [0, 3.3, 0, 3.3, 0]
    system_function.data.labels = [1, 2, 3, 4, 5]
    system_function.update()
}
