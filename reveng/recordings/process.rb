#! /usr/bin/env ruby

require 'pp'

SII9233Regs = {
    0x60 => {
        0x00 => [ "Chip Present" ],
        0x02 => [ "Chip ID (l)" ],
        0x03 => [ "Chip ID (h)" ],
        0x04 => [ "Chip Rev" ],
        0x05 => [ "SW Reset" ],
        0x06 => [ "System Status" ],
        0x07 => [ "SW Reset 2" ],
        0x08 => [ "System Ctrl 1" ],
        0x09 => [ "Port Switch" ],
        0x0a => [ "Port Switch 2" ],
        0x0b => [ "System SW Reset 2" ],
        0x0f => [ "System Pclk Stop" ],
        0x10 => [ "Hot plug Control" ],
        0x11 => [ "CEC Config" ],
        0x15 => [ "Slave Addr XVYCC" ],
        0x18 => [ "Slave Addr CEC"   ],
        0x19 => [ "Slave Addr EDID"  ],
        0x31 => [ "HDCP Debug" ],
        0x3a => [ "Video Input H Resolution (l)" ],
        0x3b => [ "Video Input H Resolution (h)" ],
        0x3c => [ "Video Input V Resolution (l)" ],
        0x3d => [ "Video Input V Resolution (h)" ],
        0x4e => [ "Video Input DE Pixel (l)" ],
        0x4f => [ "Video Input DE Pixel (h)" ],
        0x50 => [ "Video Input DE Line (l)" ],
        0x51 => [ "Video Input DE Line (h)" ],
        0x52 => [ "Video V Sync to Active Video Lines" ],
        0x53 => [ "Video V Front Porch" ],
        0x59 => [ "Video H Front Porch (l)" ],
        0x5a => [ "Video H Front Porch (h)" ],
        0x5b => [ "Video H Sync Width (l)" ],
        0x5c => [ "Video H Sync Width (h)" ],
        0x48 => [ "Video Control" ],
        0x49 => [ "Video Mode 2" ],
        0x5f => [ "Auto Output Format" ],
        0x61 => [ "Deep Color Status" ],
        0x69 => [ "Video Channel PCLK Count Base" ],
        0x6a => [ "XCLK to PCLK Update" ],
        0x6e => [ "Pixel Clock Timing (l)" ],
        0x6f => [ "Pixel Clock Timing (h)" ],
        0x70 => [ "Interrupt Status" ],
        0x71 => [ "Interrupt Status 1" ],
        0x72 => [ "Interrupt Status 2" ],
        0x73 => [ "Interrupt Status 3" ],
        0x74 => [ "Interrupt Status 4" ],
        0x75 => [ "Interrupt Unmask 1" ],
        0x77 => [ "Interrupt Unmask 3" ],
        0x7a => [ "Interrupt Info Frame Control" ],
        0x7b => [ "Interrupt Status 5" ],
        0x7c => [ "Interrupt Status 6" ],
        0x7d => [ "Interrupt Unmask 5" ],
        0x7e => [ "Interrupt Unmask 6" ],
        0x81 => [ "TMDS Analog Control 2" ],
        0x82 => [ "TMDS Termination Control" ],
        0x83 => [ "TMDS Termination Control 2" ],
        0x88 => [ "ACR Configuration 1" ],
        0x89 => [ "ACR Configuration 2" ],
        0x90 => [ "Interrupt Status 7" ],
        0x91 => [ "Interrupt Status 8" ],
        0x92 => [ "Interrupt Unmask 7" ],
        0x93 => [ "Interrupt Unmask 8" ],
        0x94 => [ "INFM_CLR" ],
        0xB4 => [ "Auto Audio Unmute Control" ],
        0xB5 => [ "Auto Exception Control" ],
        0xB6 => [ "AEC Exception Enable 1" ],
        0xBA => [ "AEC Exception Enable 2" ],
        0xBB => [ "AEC Exception Enable 3" ],
    }
}

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
            addr = self.addr & 0xfe

            reg_info = (SII9233Regs[ addr ][ self.reg_nr ] ) rescue nil
            if reg_info == nil
                reg_info = [ "<Unknown>" ]
            end

            if reg_info && self.wr
                s += reg_info[0] + "\n"
            end

            s += "    %.06f: p %4d: a 0x%02x: wr reg 0x%02x (%s) : " % [ self.time, self.packet_id, self.addr, self.reg_nr, self.ack ? "A":"N" ]

        else
            s += "    %.06f: p %4d: a 0x%02x: rd              : " % [ self.time, self.packet_id, self.addr, self.ack ? "A":"N" ]
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
