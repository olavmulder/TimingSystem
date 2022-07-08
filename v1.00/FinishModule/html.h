

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>ESP Input Form</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  </head><body>
  <form action="/get">
    name: <input type="text" name="name">
    <input type="submit" value="Submit">
  </form>
</body></html>)rawliteral";