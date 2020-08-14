const char index_html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
<title>TALLY LIGHT TEST PAGE</title>
</head>
<body>
  <h1>LED</h1>
  <form method="post">
  
    <label for="red">Red:</label>
    <input type="number" name="red" min="0" max="255" value="255"><br><br>
    <label for="green">Green:</label>
    <input type="number" name="green" min="0" max="255" value="255"><br><br>
    <label for="blue">Blue:</label>
    <input type="number" name="blue" min="0" max="255" value="255"><br><br>

    <label for="groupt">Group:</label>
    <input type="number" name="group" value="0"><br><bt>
    
    <input type="submit" name="led" value="ON">
    <input type="submit" name="led" value="OFF">
  </form>
  
  <p> red, green, and blue values for led! <p>
  <p> group is the set if multiple <p>
  <p> if 0 all should light <p>
</body>
</html>

)=====";
