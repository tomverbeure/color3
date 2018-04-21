#! /usr/bin/env ruby

require 'pp'

class I2CData
    attr_accessor :value, :time, :ack

    def initialize(value, time, ack)
        self.value = value
        self.time = time
        self.ack = ack
    end
end

class I2CPacket
    
    attr_accessor :time, :packet_id, :addr, :reg_nr, :wr, :ack
    attr_accessor :data

    def initialize(time, packet_id, addr, reg_nr, wr, ack)
        self.time = time
        self.packet_id = packet_id
        self.addr = addr
        self.wr = wr
        self.reg_nr = reg_nr
        self.ack = ack
        self.data = []
    end

    def add_data(data)
        self.data << data
    end

    def to_s
        s = ""
        if self.wr
            s += "%.06f: p %4d: a 0x%02x: wr reg 0x%02x (%s) : " % [ self.time, self.packet_id, self.addr, self.reg_nr, self.ack ? "A":"N" ]
        else
            s += "%.06f: p %4d: a 0x%02x: rd              : " % [ self.time, self.packet_id, self.addr, self.ack ? "A":"N" ]
        end

        self.data.each_with_index do |d|
            s += "0x%02x " % d.value
        end

        s
    end

end


def process_file(filename)

    line_nr = -1
    prev_packet_id = -1

    all_packets = []
    cur_packet = nil

    File.open(filename).each_line do |line|
        line_nr += 1

        next if line_nr == 0

        time,packet_id,i2c_addr,i2c_data,i2c_write,i2c_ack = line.strip.split(/,/)

        time = time.to_f
        packet_id = packet_id.to_i(16)
        i2c_addr = i2c_addr.to_i(16)
        i2c_data = i2c_data.to_i(16)
        i2c_write = i2c_write == "Write"
        i2c_ack = i2c_ack == "ACK"

        if packet_id != prev_packet_id  
            if i2c_write
                cur_packet = I2CPacket.new(time, packet_id, i2c_addr, i2c_data, i2c_write, i2c_ack)
                all_packets << cur_packet
            else
                cur_packet = I2CPacket.new(time, packet_id, i2c_addr, nil, i2c_write, i2c_ack)
                all_packets << cur_packet

                data = I2CData.new(i2c_data, time, i2c_ack)
                cur_packet.add_data(data)
            end
        else
            data = I2CData.new(i2c_data, time, i2c_ack)
            cur_packet.add_data(data)
        end

        prev_packet_id = packet_id
    end

    return all_packets
end


all_packets = process_file(ARGV[0])

all_packets.each do |p|
    puts p.to_s
end
