require 'cigihost'
require 'powermate'

host = CigiHost.new(:receiveport => 9000, :ig_address => '127.0.0.1', :ig_port => 8000)

pmate = PowerMate.new

pmate.on_rotate do |event|
  host.yaw += event.value
end

Thread.new { pmate.each_event{} }

host.run do
  host.yaw += 0.1
end
