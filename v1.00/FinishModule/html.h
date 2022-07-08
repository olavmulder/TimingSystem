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
</style>
)rawliteral";

const char htmlHeader1[] = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>ESP TimingSystem</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  )rawliteral";

const char htmlNavBar[] = R"rawliteral(
  </head><body>
    <ul>  
      <li><a href="/">Home</a></li>
      <li><a href="/time">Time</a></li>
      <li><a href="/users">Users</a></li>
      <li><a href="/ImportUsers">Import users</a></li>
    </ul>
  )rawliteral";
char *htmlHeader;

void HtmlCombineHeader(){
  htmlHeader = (char*)malloc(strlen(htmlHeader1) + \
                    strlen(htmlCss)+strlen(htmlNavBar)+1);

  strcat(htmlHeader,htmlHeader1);
  strcat(htmlHeader,htmlCss);
  strcat(htmlHeader,htmlNavBar);
}
 
const char htmlFooter[] = R"rawliteral(
  </body></html>
  )rawliteral";

  
const char htmlInputName[] = R"rawliteral(
  <form action="/get">
    name: <input type="text" name="name">
    <input type="submit" value="Submit">
  </form>
)rawliteral";

//const char htmlReadmeText[] = R"rawliteral"
