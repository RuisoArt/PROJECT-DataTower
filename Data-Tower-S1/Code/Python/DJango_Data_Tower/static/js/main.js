var ctx = document.getElementById('myChart').getContext('2d');
var ctx2 = document.getElementById('myChart2').getContext('2d');
var ctx3 = document.getElementById('myChart3').getContext('2d');
var ctx4 = document.getElementById('myChart4').getContext('2d');
var ctx5 = document.getElementById('myChart5').getContext('2d');
var ctx6 = document.getElementById('myChart6').getContext('2d');
var ctx7 = document.getElementById('myChart7').getContext('2d');
var ctx8 = document.getElementById('myChart8').getContext('2d');
var ctx9 = document.getElementById('myChart9').getContext('2d');
var ctx10 = document.getElementById('myChart10').getContext('2d');
var ctx11 = document.getElementById('myChart11').getContext('2d');


var graphDataT1 = {
    type: 'line',
    data: {
        labels: ['1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40'],
        datasets: [{label: 'Temperatura 1', data: [1,1,1,1,1,1,1,1.1,1.1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], backgroundColor: ['rgb(73,198,230)',],borderColor: ['rgba(73, 198, 230, 1)',],borderWidth: 3}]
    },options: {}
}
var graphDataT2 = {
    type: 'line',
    data: {
        labels: ['1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40'],
        datasets: [{label: 'Temperatura 2', data: [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], backgroundColor: ['rgb(255,99,132)',], borderColor: ['rgba(255, 99, 132, 1)',], borderWidth: 3}]
    }, options: {    }
}
var graphDataT3 = {
    type: 'line',
    data: {
        labels: ['1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40'],
        datasets: [{label: 'Temperatura 3', data: [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], backgroundColor: ['rgb(246,185,76)',], borderColor: ['rgba(246,185,76 , 1)',], borderWidth: 3}]
    }, options: {    }
}
var graphDataT4 = {
    type: 'line',
    data: {
        labels: ['1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40'],
        datasets: [{label: 'Temperatura 4', data: [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], backgroundColor: ['rgb(126,248,88)',], borderColor: ['rgba(126,248,88 ,1)',], borderWidth: 3}]
    }, options: {    }
}
var graphDataT5 = {
    type: 'line',
    data: {
        labels: ['1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40'],
        datasets: [{label: 'Temperatura 5', data: [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], backgroundColor: ['rgb(122,51,234)',], borderColor: ['rgba(122,51,234,1)',], borderWidth: 3}]
    }, options: {    }
}
var graphDataT6 = {
    type: 'line',
    data: {
        labels: ['1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40'],
        datasets: [{label: 'Temperatura 6', data: [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], backgroundColor: ['rgb(43,38,150)',], borderColor: ['rgb(43,38,150,1)',], borderWidth: 3}]
    }, options: {    }
}
var graphDataT7 = {
    type: 'line',
    data: {
        labels: ['1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40'],
        datasets: [{label: 'Temperatura 7', data: [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], backgroundColor: ['rgb(234,177,246)',], borderColor: ['rgba(234,177,246,1)',], borderWidth: 3}]
    }, options: {    }
}
var graphDataT8 = {
    type: 'line',
    data: {
        labels: ['1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40'],
        datasets: [{label: 'Temperatura 8', data: [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], backgroundColor: ['rgb(0,248,164)',], borderColor: ['rgba(0,248,164,1)',], borderWidth: 3}]
    }, options: {    }
}
var graphDataT9 = {
    type: 'line',
    data: {
        labels: ['1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40'],
        datasets: [{label: 'Corriente Pico', data: [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], backgroundColor: ['rgb(229,133,78)',], borderColor: ['rgba(229,133,78,1)',], borderWidth: 3}]
    }, options: {    }
}
var graphDataT10 = {
    type: 'line',
    data: {
        labels: ['1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40'],
        datasets: [{label: 'Corriente RMS', data: [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], backgroundColor: ['rgb(210,178,1)',], borderColor: ['rgba(210,178,1,1)',], borderWidth: 3}]
    }, options: {    }
}
var graphDataT11 = {
    type: 'line',
    data: {
        labels: ['1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40'],
        datasets: [{label: 'Potencia', data: [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], backgroundColor: ['rgb(239,11,54)',], borderColor: ['rgba(2239,11,54,1)',], borderWidth: 3}]
    }, options: {    }
}



var myChart = new Chart(ctx, graphDataT1);
var myChart2 = new Chart(ctx2, graphDataT2);
var myChart3 = new Chart(ctx3, graphDataT3);
var myChart4 = new Chart(ctx4, graphDataT4);
var myChart5 = new Chart(ctx5, graphDataT5);
var myChart6 = new Chart(ctx6, graphDataT6);
var myChart7 = new Chart(ctx7, graphDataT7);
var myChart8 = new Chart(ctx8, graphDataT8);
var myChart9 = new Chart(ctx9, graphDataT9);
var myChart10 = new Chart(ctx10, graphDataT10);
var myChart11 = new Chart(ctx11, graphDataT11);


var socket = new WebSocket('ws://localhost:8000/ws/some_url/');

socket.onmessage = function (event){
    var dataDjango = JSON.parse(event.data);
    console.log(dataDjango);

    var newDataT1 = graphDataT1.data.datasets[0].data;
    newDataT1.shift();
    newDataT1.push(dataDjango.message);
    var newDataT2 = graphDataT2.data.datasets[0].data;
    newDataT2.shift();
    newDataT2.push(dataDjango.messageNi);
    var newDataT3 = graphDataT3.data.datasets[0].data;
    newDataT3.shift();
    newDataT3.push(dataDjango.messageSan);
    var newDataT4 = graphDataT4.data.datasets[0].data;
    newDataT4.shift();
    newDataT4.push(dataDjango.messageYon);
    var newDataT5 = graphDataT5.data.datasets[0].data;
    newDataT5.shift();
    newDataT5.push(dataDjango.messageGo);
    var newDataT6 = graphDataT6.data.datasets[0].data;
    newDataT6.shift();
    newDataT6.push(dataDjango.messageRoku);
    var newDataT7 = graphDataT7.data.datasets[0].data;
    newDataT7.shift();
    newDataT7.push(dataDjango.messageNana);
    var newDataT8 = graphDataT8.data.datasets[0].data;
    newDataT8.shift();
    newDataT8.push(dataDjango.messageHachi);
    var newDataT9 = graphDataT9.data.datasets[0].data;
    newDataT9.shift();
    newDataT9.push(dataDjango.messageKyu);
    var newDataT10 = graphDataT10.data.datasets[0].data;
    newDataT10.shift();
    newDataT10.push(dataDjango.messageJu);
    var newDataT11 = graphDataT11.data.datasets[0].data;
    newDataT11.shift();
    newDataT11.push(dataDjango.messageJuichi);


    graphDataT1.data.datasets[0].data = newDataT1;
    graphDataT2.data.datasets[0].data = newDataT2;
    graphDataT3.data.datasets[0].data = newDataT3;
    graphDataT4.data.datasets[0].data = newDataT4;
    graphDataT5.data.datasets[0].data = newDataT5;
    graphDataT6.data.datasets[0].data = newDataT6;
    graphDataT7.data.datasets[0].data = newDataT7;
    graphDataT8.data.datasets[0].data = newDataT8;
    graphDataT9.data.datasets[0].data = newDataT9;
    graphDataT10.data.datasets[0].data = newDataT10;
    graphDataT11.data.datasets[0].data = newDataT11;

    myChart.update();
    myChart2.update();
    myChart3.update();
    myChart4.update();
    myChart5.update();
    myChart6.update();
    myChart7.update();
    myChart8.update();
    myChart9.update();
    myChart10.update();
    myChart11.update();

    document.querySelector('#app1').innerText = dataDjango.message;
    document.querySelector('#app2').innerText = dataDjango.messageNi;
    document.querySelector('#app3').innerText = dataDjango.messageSan;
    document.querySelector('#app4').innerText = dataDjango.messageYon;
    document.querySelector('#app5').innerText = dataDjango.messageGo;
    document.querySelector('#app6').innerText = dataDjango.messageRoku;
    document.querySelector('#app7').innerText = dataDjango.messageNana;
    document.querySelector('#app8').innerText = dataDjango.messageHachi;
    document.querySelector('#app9').innerText = dataDjango.messageKyu;
    document.querySelector('#app10').innerText = dataDjango.messageJu;
    document.querySelector('#app11').innerText = dataDjango.messageJuichi;


}