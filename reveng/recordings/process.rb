#! /usr/bin/env ruby

require 'pp'

# I2C Addresses:
# 0x60, 0x68 (0x0x62, 0x6a): local fixed 
# 0x64, 0xc0, 0xe0: prorammable

SII9233Regs = {
    0x60 => {
        0x00 => { :name => "Chip Vendor ID (l)" },
        0x01 => { :name => "Chip Vendor ID (h)" },
        0x02 => { :name => "Chip Device ID (l)" },
        0x03 => { :name => "Chip Device ID (h)" },
        0x04 => { :name => "Chip Rev" },
        0x05 => { :name => "SW Reset" },
        0x06 => { :name => "System Status" },
        0x07 => { :name => "SW Reset 2" },
        0x08 => { :name => "System Ctrl 1" },
        0x09 => { :name => "Port Switch" },
        0x0a => { :name => "Port Switch 2" },
        0x0b => { :name => "System SW Reset 2" },
        0x0f => { :name => "System Pclk Stop" },
        0x10 => { :name => "Hot plug Control" },
        0x11 => { :name => "CEC Config" },
        0x14 => { :name => "Unknown 0x60_0x14" },
        0x15 => { :name => "Slave Addr XVYCC" },
        0x16 => { :name => "Slave Addr Reserved 1" },
        0x17 => { :name => "Slave Addr Reserved 2" },
        0x18 => { :name => "Slave Addr CEC"   },
        0x19 => { :name => "Slave Addr EDID"  },
        0x2e => { :name => "Unknown 0x60_0x2e" },
        0x2f => { :name => "Unknown 0x60_0x2f" },
        0x31 => { :name => "HDCP Debug" },
        0x3a => { :name => "Video Input H Resolution (l)" },
        0x3b => { :name => "Video Input H Resolution (h)" },
        0x3c => { :name => "Video Input V Resolution (l)" },
        0x3d => { :name => "Video Input V Resolution (h)" },
        0x4e => { :name => "Video Input DE Pixel (l)" },
        0x4f => { :name => "Video Input DE Pixel (h)" },
        0x50 => { :name => "Video Input DE Line (l)" },
        0x51 => { :name => "Video Input DE Line (h)" },
        0x52 => { :name => "Video V Sync to Active Video Lines" },
        0x53 => { :name => "Video V Front Porch" },
        0x57 => { :name => "Unknown 0x60_0x57" },
        0x59 => { :name => "Video H Front Porch (l)" },
        0x5a => { :name => "Video H Front Porch (h)" },
        0x5b => { :name => "Video H Sync Width (l)" },
        0x5c => { :name => "Video H Sync Width (h)" },
        0x48 => { :name => "Video Control" },
        0x49 => { :name => "Video Mode 2" },
        0x5f => { :name => "Auto Output Format" },
        0x61 => { :name => "Deep Color Status" },
        0x69 => { :name => "Video Channel PCLK Count Base" },
        0x6a => { :name => "XCLK to PCLK Update" },
        0x6e => { :name => "Pixel Clock Timing (l)" },
        0x6f => { :name => "Pixel Clock Timing (h)" },
        0x70 => { :name => "Interrupt Status" },
        0x71 => { :name => "Interrupt Status 1" },
        0x72 => { :name => "Interrupt Status 2" },
        0x73 => { :name => "Interrupt Status 3" },
        0x74 => { :name => "Interrupt Status 4" },
        0x75 => { :name => "Interrupt Unmask 1" },
        0x77 => { :name => "Interrupt Unmask 3" },
        0x79 => { :name => "Interrupt Control" },
        0x7a => { :name => "Interrupt Info Frame Control" },
        0x7b => { :name => "Interrupt Status 5" },
        0x7c => { :name => "Interrupt Status 6" },
        0x7d => { :name => "Interrupt Unmask 5" },
        0x7e => { :name => "Interrupt Unmask 6" },
        0x81 => { :name => "TMDS Analog Control 2" },
        0x82 => { :name => "TMDS Termination Control" },
        0x83 => { :name => "TMDS Termination Control 2" },
        0x88 => { :name => "ACR Configuration 1" },
        0x89 => { :name => "ACR Configuration 2" },
        0x90 => { :name => "Interrupt Status 7" },
        0x91 => { :name => "Interrupt Status 8" },
        0x92 => { :name => "Interrupt Unmask 7" },
        0x93 => { :name => "Interrupt Unmask 8" },
        0x94 => { :name => "INFM_CLR" },
        0xb4 => { :name => "Auto Audio Unmute Control" },
        0xb5 => { :name => "Auto Exception Control" },
        0xb6 => { :name => "AEC Exception Enable 1" },
        0xb7 => { :name => "AEX Exception Enable 2" },
        0xb8 => { :name => "AEX Exception Enable 3" },
        0xba => { :name => "AVC En 2" },
        0xbc => { :name => "Unknown 0x60_0xbc" },
        0xbb => { :name => "ECC Control" },
        0xf0 => { :name => "Video Auto Output Format" },
    },
    # XVYCC
    0x64 => {
    },
    0x68 => {
        0x14 => { :name => "LKTHRESH1" },
        0x17 => { :name => "TCLK_FS" },
        0x18 => { :name => "ACR_CTRL3" },
        0x26 => { :name => "RX_I2S_CTRL1" },
        0x27 => { :name => "RX_I2S_CTRL2" },
        0x29 => { :name => "RX_AUDIO_CTRL" },
        0x2e => { :name => "RX_AUDIO_SWAP" },
        0x34 => { :name => "RX_AUDP_STAT", :exclude => false},
        0x37 => { :name => "RX_AUDP_MUTE" },
        0x60 => { :name => "SPD_TYPE" },
        0x7f => { :name => "SPD_DECODE" },
        0xa0 => { :name => "MPEG_TYPE" },
        0xbf => { :name => "MPEG_DECODE" },
    },
    0xee => {
        0x01 => { :name => "EN_EDID" },
        0x02 => { :name => "EDID_FIFO_ADDR" },
        0x03 => { :name => "EDID_FIFO_DATA" },
        0x04 => { :name => "EDID_FIFO_SEL" },
        0x05 => { :name => "NVM_COMMAND" },
        0x07 => { :name => "NVM_COMMAND_DONE" },
        0x08 => { :name => "BSM_INIT" },
        0x09 => { :name => "BSM_STAT" },
        0x10 => { :name => "NVM_STAT" },
        0x13 => { :name => "HDP_HW_CTRL" },
        0x1a => { :name => "CECPA_ADDR" },
        0x40 => { :name => "RPI_AUTO_CONFIG" },
        0x41 => { :name => "WAIT_CYCLE" },
        0xd0 => { :name => "CLKDETECT_STATUS" },
        0xd1 => { :name => "PWR5V_STATUS" },
        0xd4 => { :name => "CBUS_PAD_SC" },
        0xe9 => { :name => "DRIVE_CNTL" },
    },
    0x00 => {
        0x00 => { :name => "* RX_ACR_CTRL1" },
        0x02 => { :name => "* RX_FREQ_SVAL" },
        0x06 => { :name => "* RX_HW_N_ADDR" },
        0x0a => { :name => "* RX_AFE_DDR_CONF" },
        0x0b => { :name => "* RX_AFE_DSA_CONF" },
        0x0c => { :name => "* RX_HW_CTS" },
        0x1a => { :name => "* RX_BKSV" },
        0x1f => { :name => "* RX_RI_PRIME" },
        0x21 => { :name => "* RX_AKSV" },
        0x28 => { :name => "* RX_I2S_MAP" },
        0x2a => { :name => "* RX_CH_STATUS1" },
        0x2d => { :name => "* RX_MUTE_DIV" },
        0x30 => { :name => "* RX_CH_STATUS4" },
        0x31 => { :name => "* RX_HDCP_CTRL, RX_CH_STATUS5" },
        0x32 => { :name => "* RX_HDCP_STAT" },
        0x35 => { :name => "* RX_HDMI_CRIT1" },
        0x38 => { :name => "* RX_HDMI_CRIT2" },
        0x39 => { :name => "* RX_FIFO_DIFF" },
        0x3e => { :name => "* PD_SYS2" },
        0x3f => { :name => "* PD_SYS" },
        0x7c => { :name => "* RX_ECC_THRES" },
        0x8c => { :name => "* RX_PLL_IOPPC" },
        0x8d => { :name => "* RX_PLL_CGC" },
        0xcd => { :name => "* RX_HDCP_ERR" },
    },
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
    
    attr_accessor :time, :packet_id, :addr, :reg_nr, :wr, :ack, :line_nr
    attr_accessor :data

    def initialize(time, packet_id, addr, reg_nr, wr, ack, line_nr)
        self.time = time
        self.packet_id = packet_id
        self.addr = addr
        self.wr = wr
        self.reg_nr = reg_nr
        self.ack = ack
        self.data = []
        self.line_nr = line_nr
    end

    def add_data(data)
        self.data << data
    end

    def reg_info(addr, reg_nr)
        reg_info = (SII9233Regs[ addr ][ reg_nr ] ) rescue nil
        if reg_info == nil
            reg_info = (SII9233Regs[ 0x00 ][ reg_nr ] ) rescue nil
            if reg_info == nil
                reg_info = { :name => "<Unknown>" }
            end
        end

        reg_info
    end

    def reg_name(addr, reg_nr)
        self.reg_info(addr, reg_nr)[:name]
    end

    def to_s
        s = ""
        if self.wr
            addr = self.addr & 0xfe

            if self.data.size > 0 && self.addr != 0xEE && self.reg_nr !=  0x03

                reg_names = []
                0.upto(self.data.size-1) do |idx|
                    r = self.reg_name(addr, self.reg_nr + idx)
                    v = self.data[idx].value
                    reg_names << "%s = 0x%02x" % [ r, v]
                end

                s += reg_names.join(",\n") + "\n"
            else
                s += self.reg_name(addr, self.reg_nr) + "\n"
            end

            s += "                        %.06f: p %4d: a 0x%02x: wr reg 0x%02x (%s) : " % [ self.time, self.packet_id, self.addr, self.reg_nr, self.ack ? "A":"N" ]

        else
            s += "                        %.06f: p %4d: a 0x%02x: rd              : " % [ self.time, self.packet_id, self.addr, self.ack ? "A":"N" ]
        end

        self.data.each_with_index do |d|
            s += "0x%02x " % d.value
        end

        s
    end

    def to_c
        s = ""

        if self.reg_info(self.addr, self.reg_nr)[:exclude]
            s += "    // Excluded: %s\n" % self.reg_name(self.addr & 0xfe, self.reg_nr)
            return s
        end

        if self.wr
            s += "    // line nr: %d, packet id: %d\n" % [ self.line_nr, self.packet_id ]
            addr = self.addr & 0xfe

            if self.data.size > 0 && self.addr != 0xEE && self.reg_nr !=  0x03

                reg_names = []
                0.upto(self.data.size-1) do |idx|
                    r = self.reg_name(addr, self.reg_nr + idx)
                    v = self.data[idx].value
                    reg_names << "    // (0x%02x) (0x%02x) %s = 0x%02x" % [ self.addr, self.reg_nr + idx, r, v ]
                end

                s += reg_names.join("\n") + "\n"
            else
                s += "    // (0x%02x) (0x%02x) %s\n" % [ self.addr, self.reg_nr, self.reg_name(addr, self.reg_nr) ]
            end

            if self.data.size == 0
                # Initiate a read operations
                s += "    i2c_write_reg_nr(&sii9233_i2c_ctx, 0x%02x, 0x%02x);\n" % [ self.addr, self.reg_nr ]

            elsif self.data.size == 1
                # Write operation with 1 byte
                s += "    i2c_write_reg(&sii9233_i2c_ctx, 0x%02x, 0x%02x, 0x%02x);\n" % [ self.addr, self.reg_nr, self.data.first.value ]
            else
                # Multi-byte write operation
                s += "    {\n";
                s += "    byte buf[%d] = { %s };\n" % [ self.data.size, self.data.collect{ |d| "0x%02x" % d.value }.join(", ") ]
                s += "    i2c_write_regs(&sii9233_i2c_ctx, 0x%02x, 0x%02x, buf, %d);\n" % [ self.addr, self.reg_nr, self.data.size ]
                s += "    }\n";
            end
        else
            # Read data...
            s += "    {\n"
            s += "    byte buf[%s];\n" % [ self.data.size ]
            s += "    i2c_read_buf(&sii9233_i2c_ctx, 0x%02x, buf, %d);\n" % [ self.addr, self.data.size ]
            s += "    }\n"
             
        end

#        self.data.each_with_index do |d|
#            s += "0x%02x " % d.value
#        end

        s += "\n"

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
        packet_id = packet_id.to_i
        i2c_addr = i2c_addr.to_i(16)
        i2c_data = i2c_data.to_i(16)
        i2c_write = i2c_write == "Write"
        i2c_ack = i2c_ack == "ACK"

        if packet_id != prev_packet_id  
            if i2c_write
                cur_packet = I2CPacket.new(time, packet_id, i2c_addr, i2c_data, i2c_write, i2c_ack, line_nr)
                all_packets << cur_packet
            else
                cur_packet = I2CPacket.new(time, packet_id, i2c_addr, nil, i2c_write, i2c_ack, line_nr)
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

puts
all_packets.each do |p|

    if nil
        real_write = p.wr && p.data.size > 0 
        puts "%5d: %s" % [ p.packet_id, (real_write ? "W":"R") ]
        if real_write
            puts p.to_s
        end
    elsif 1
            puts p.to_c
    elsif 1
            puts p.to_s
    end
end
