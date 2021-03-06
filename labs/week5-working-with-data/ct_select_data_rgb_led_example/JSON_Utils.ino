// The code on this tab is a general template for downloading data in JSON format from an API
// You can re-use it in all your programs without changing anything, except for the values you pass into the function (host, url, port)

// The values you pass into this function are the host name of the API you want to talk to (e.g. "api.darksky.net", "maker.ifttt.com"),
// the URL for the GET Request you want to make, and the Port Number you want to use (80 for an unsecured connection, 443 for a secure one)

String getJson(String host, String url, const int port)  // This is a non-void function, which means that it returns a value (in this case a String)
{
  String response; // Create a string to hold the data you receive from the API

  if (port == 80)  // If you are using an unsecured connection over Port 80
  {
    if (client.connect(host.c_str(), port))  // Connect to the server using the specified Port Number
    {
      Serial.println("Connected to server."); // Print a message to the Serial to let you know you've connected sucessfully
      client.println("GET " + url + " HTTP/1.1"); // Send your GET Request to the server
      client.println("Host: " + host);
      client.println("Connection: close"); // Close the connection to the server
      client.println(); // Remember to print a line break at the end - this is to let the server know you've finished sending your request
    }

    while (client.connected())  // While you are connected to the server
    {
      String line = client.readStringUntil('\n'); // Read in the data it is sending unitl you hit a line break
      if (line == "\r")
      {
        break;
      }
      Serial.println(line); // Print out the data you've got back to the Serial to check the response is OK (Response Code 200)
    }

    response = client.readString(); // create a new String and copy the JSON data received from the server into it
    Serial.println(response); // print out the JSON data to the Serial

  }
  else if (port == 443)  // If you are using a secure connection over Port 443

  {
    if (sslClient.connect(host.c_str(), port))  // Connect to the server using the Port 443 (secure connection)
    {
      Serial.println("Connected to SSL server."); // Print a message to the Serial to let you know you've connected sucessfully
      sslClient.println("GET " + url + " HTTP/1.1"); // Send your GET Request to the server
      sslClient.println("Host: " + host);
      sslClient.println("Connection: close"); // Close the connection to the server
      sslClient.println(); // Remember to print a line break at the end - this is to let the server know you've finished sending your request
    }

    while (sslClient.connected())  // While you are connected to the server
    {
      String line = sslClient.readStringUntil('\n'); // Read in the data it is sending unitl you hit a line break
      if (line == "\r")
      {
        break;
      }
      Serial.println(line); // Print out the data you've got back to the Serial to check the response is OK (Response Code 200)
    }

    response = sslClient.readString(); // create a new String and copy the JSON data received from the server into it
    Serial.println(response); // print out the JSON data to the Serial
  }


  return response; // return the String called response


}
