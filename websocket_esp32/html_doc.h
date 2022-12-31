const char webpageCode[] PROGMEM ="<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>PSR</title><link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css\"><style>.card{box-shadow:04px8px0rgba(0,0,0,0.2);max-width:300px;margin:auto;text-align:center;border-radius:5px;}.title{color:grey;font-size:18px;}button{border:none;outline:0;display:inline-block;padding:8px;color:white;background-color:#000;text-align:center;cursor:pointer;width:100%;font-size:18px;}a{text-decoration:none;font-size:22px;color:black;}button:hover,a:hover{opacity:0.7;}</style></head><body><section><br><br><div class=\"card\"><br><h1>Partha Singha Roy</h1><p class=\"title\">I am a Web Developer, IoT Enthusiast and Electronics Hobbyist.</p><a href=\"#\"><i class=\"fa fa-dribbble\"></i></a><a href=\"#\"><i class=\"fa fa-twitter\"></i></a><a href=\"#\"><i class=\"fa fa-linkedin\"></i></a><a href=\"#\"><i class=\"fa fa-facebook\"></i></a><p><button type=\"button\">Contact</button></p></div></section></body></html>";



//
//=====(<!DOCTYPE HTML><html><head>  <title>ESP32 Web Server</title></head>
//<!-------------------------------C S S------------------------------>
//<style>
//  #btn
//  {
//    display: inline-block;
//    text-decoration: none;
//    background: #8CD460;
//    color: rgba(255,255,255, 0.80);
//    font-weight: bold;
//    font: 60px arial, sans-serif;
//    width: 150px;
//    height: 150px;
//    line-height: 150px;
//    border-radius: 50%;
//    text-align: center;
//    vertical-align: middle;
//    overflow: hidden;
//    box-shadow: 0px 0px 0px 8px #8CD460;
//    border: solid 2px rgba(255,255,255, 0.47);
//    transition: 0.5s;
//  }
//  body {text-align:center; font-family:"Calibri"; background-color:rgba(0, 3, 8, 0.26)}
//  h1   {color: rgba(0, 0, 255, 0.87); font-size: 50px;}
//</style>
//<!------------------------------H T M L----------------------------->
//<body>
//   <h1>E S P 3 2<br>WebSocket Server</h1>
//   <a href="#" id="btn" ONCLICK='button()'> </a>
//<!-----------------------------JavaScript--------------------------->
//  <script>
//     InitWebSocket()
//     function InitWebSocket()
//     {
//       websock = new WebSocket('ws://'+window.location.hostname+':81/'); 
//       websock.onmessage = function(evt)
//       {
//          JSONobj = JSON.parse(evt.data);
//          document.getElementById('btn').innerHTML = JSONobj.LEDonoff;
//          if(JSONobj.LEDonoff == 'ON')
//          {
//            document.getElementById('btn').style.background='#FF0000';
//            document.getElementById('btn').style["boxShadow"] = "0px 0px 0px 8px #FF0000";
//          }
//          else
//          {
//            document.getElementById('btn').style.background='#111111';
//            document.getElementById('btn').style["boxShadow"] = "0px 0px 0px 8px #111111";
//          }
//       }
//     }
//     //-------------------------------------------------------------
//     function button()
//     {
//        btn = 'LEDonoff=ON';
//        if(document.getElementById('btn').innerHTML == 'ON')
//        {
//          btn = 'LEDonoff=OFF';
//        }
//        websock.send(btn);
//     }
//  </script>
//</body>
//</html>
//)=====";
