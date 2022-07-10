const char htmlCss[] = R"rawliteral(
<style>
body {
  background-color: grey;
}
h1 {
  color: #000000;
  text-align: center;
}
p {
  text-align: right;
}
ul {
  list-style-type: none;
  margin: 0;
  padding: 0;
  overflow: hidden;
  background-color: #333;
}
li {
  float: left;
}
li a {
  display: block;
  color: white;
  text-align: center;
  padding: 14px 16px;
  text-decoration: none;
}
/* Change the link color to #111 (black) on hover */
li a:hover {
  background-color: #111;
}
</style>)rawliteral";
const char htmlGoback[] = R"rawliteral(
  <!DOCTYPE html>
  <html>
    <head>
        <title>Test</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
          <script>
            function goBack() {
              window.location.href = "http://192.168.4.1/time";
            }
          </script>
          </head><body onload="goBack();"></body></html>)rawliteral";
const char htmlHeader1[] = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>ESP TimingSystem</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">)rawliteral";

const char htmlNavBar[] = R"rawliteral(
  </head><body><ul>  
      <li><a href="/">Home</a></li>
      <li><a href="/time">Time</a></li>
      <li><a href="/users">Users</a></li>
      <li><a href="/ImportUsers">Import users</a></li>
    </ul>
  )rawliteral";
String htmlHeader;

void HtmlCombineHeader(){
  htmlHeader =  htmlHeader1;
  htmlHeader += htmlCss;
  htmlHeader += htmlNavBar;
}
 
const char htmlFooter[] = R"rawliteral(
  </body></html>)rawliteral";

  
const char htmlInputName[] = R"rawliteral(
  <form action="/get">
    name: <input type="text" name="name">
    <input type="submit" value="Submit">
  </form>
)rawliteral";
const char htmlUserSelectForm[] = R"rawliteral(
    <form action="/selectUser" id="selectUser">
      <label for="selectUser">Select user:</label>
      <select name="selectUser" id="selectUser" form="selectUser">
  )rawliteral";
const char htmlUserSelectForm2 [] = R"rawliteral(
  </select>
  <input type="submit">
  </form><br>)rawliteral";
//const char htmlReadmeText[] = R"rawliteral"
