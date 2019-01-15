require "socket"

host = "test.mk16.de:80".split(":")
path = "/scriptFiles/"

port = 2000

server = TCPServer.new(port)

loop do
  client = server.accept
  
  x = client.gets.split(" ")
  response = ""
  
  if(x[1] != "/")
    socket = TCPSocket.open(host[0], host[1])
    socket.print "GET #{path}#{x[1]} HTTP/1.0\r\nHost: #{host[0]}\r\n\r\n"
    response = socket.read
  else
    response = "#{x[2]} 200 OK\r\nConnection: close\r\nContent-Type: text/plain\r\n\r\n#{host[0]}:#{host[1]}#{path}"
  end
  
  client.puts response
  client.close
end