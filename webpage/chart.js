
const ctx = document.getElementById("osciCanvas").getContext('2d');
const myChart = new Chart(ctx, {
    type: 'line',
    data: {
        labels: [10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10],
        datasets: [{
            pointRadius: 0,
            label: 'Oscillscope',
            data: [10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10],
            backgroundColor: [
                'rgba(75, 192, 192,0.2)'
            ],
            borderColor: [
                'rgb(75, 192, 192)'
            ],
            // fill: true,
            borderWidth: 1,
            spanGaps: true,
            showLine: true,
            tension: 0.5
        }]
    },

    options: {
        responsive: true,
        maintainAspectRatio: false,
        scales: {
            y: {
                min: 0,
                // max:1000
            }

        },
        animation: {
            duration: 0
        }
    }
});

const system = document.getElementById("sysCanvas").getContext('2d');
const system_function = new Chart(system, {
    type: 'line',
    data: {
        labels: [1, 2, 3, 4,5],
        datasets: [{
            pointRadius: 0,
            label: 'Oscillscope',
            data: [0, 3.3, 0, 3.3, 0],
            backgroundColor: [
                'rgba(75, 192, 192,0.1)'
            ],
            borderColor: [
                'rgb(75, 192, 192)'
            ],
            fill: true,
            borderWidth: 1,
            spanGaps: true,
            showLine: true,
            // tension: 0.5
            tension: 0,
            // stepped: true,

        }]
    },

    options: {
        responsive: true,
        maintainAspectRatio: false,
        scales: {
            y: {
                min: 0,
                max:4
            }
        }
    }
});


const bar = document.getElementById("dftCanvas").getContext('2d');
const myBar = new Chart(bar, {
    type: 'bar',
    data: {
        labels: [10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10],
        datasets: [{
            pointRadius: 0,
            label: 'Oscillscope',
            data: [10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10],
            backgroundColor: [
                'rgba(255, 99, 132, 0.2)',
                'rgba(255, 159, 64, 0.2)',
                'rgba(255, 205, 86, 0.2)',
                'rgba(75, 192, 192, 0.2)',
                'rgba(54, 162, 235, 0.2)',
                'rgba(153, 102, 255, 0.2)',
                'rgba(201, 203, 207, 0.2)'
            ],
            borderColor: [
                'rgb(255, 99, 132)',
                'rgb(255, 159, 64)',
                'rgb(255, 205, 86)',
                'rgb(75, 192, 192)',
                'rgb(54, 162, 235)',
                'rgb(153, 102, 255)',
                'rgb(201, 203, 207)'
            ],
            // fill: true,
            borderWidth: 1,
            spanGaps: true,
            showLine: true,
            tension: 0.5
        }]
    },

    options: {
        responsive: true,
        maintainAspectRatio: false,
        scales: {
            y: {
                min: 0,
                // max:600
            }

        },
        animation: {
            duration: 0
        }
    }
});
