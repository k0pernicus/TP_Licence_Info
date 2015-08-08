<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="switches(7:0)" />
        <signal name="led(7:0)" />
        <signal name="d(7:0)" />
        <signal name="anodes(3:0)" />
        <signal name="d(15:0)" />
        <signal name="d(15:8)" />
        <signal name="clk" />
        <signal name="sevenseg(6:0)" />
        <port polarity="Input" name="switches(7:0)" />
        <port polarity="Output" name="led(7:0)" />
        <port polarity="Output" name="anodes(3:0)" />
        <port polarity="Input" name="clk" />
        <port polarity="Output" name="sevenseg(6:0)" />
        <blockdef name="ibuf8">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <rect width="96" x="128" y="-44" height="24" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
        </blockdef>
        <blockdef name="obuf8">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <rect width="64" x="0" y="-44" height="24" />
            <rect width="96" x="128" y="-44" height="24" />
        </blockdef>
        <blockdef name="afficheur">
            <timestamp>2014-9-26T12:2:53</timestamp>
            <line x2="0" y1="32" y2="32" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
            <rect width="256" x="64" y="-128" height="192" />
        </blockdef>
        <blockdef name="constant">
            <timestamp>2006-1-1T10:10:10</timestamp>
            <rect width="112" x="0" y="0" height="64" />
            <line x2="112" y1="32" y2="32" x1="144" />
        </blockdef>
        <block symbolname="ibuf8" name="XLXI_1">
            <blockpin signalname="switches(7:0)" name="I(7:0)" />
            <blockpin signalname="d(7:0)" name="O(7:0)" />
        </block>
        <block symbolname="obuf8" name="XLXI_2">
            <blockpin signalname="d(7:0)" name="I(7:0)" />
            <blockpin signalname="led(7:0)" name="O(7:0)" />
        </block>
        <block symbolname="constant" name="XLXI_5">
            <attr value="00" name="CValue">
                <trait delete="all:1 sym:0" />
                <trait editname="all:1 sch:0" />
                <trait valuetype="BitVector 2 Hexadecimal" />
            </attr>
            <blockpin signalname="d(15:8)" name="O" />
        </block>
        <block symbolname="afficheur" name="XLXI_7">
            <blockpin signalname="d(15:0)" name="din(15:0)" />
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="anodes(3:0)" name="anodes(3:0)" />
            <blockpin signalname="sevenseg(6:0)" name="sevenseg(6:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="624" y="768" name="XLXI_1" orien="R0" />
        <instance x="2464" y="1440" name="XLXI_2" orien="R0" />
        <branch name="switches(7:0)">
            <wire x2="624" y1="736" y2="736" x1="592" />
        </branch>
        <iomarker fontsize="28" x="592" y="736" name="switches(7:0)" orien="R180" />
        <branch name="d(7:0)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="2320" y="1456" type="branch" />
            <wire x2="1648" y1="736" y2="736" x1="848" />
            <wire x2="1648" y1="736" y2="1408" x1="1648" />
            <wire x2="2320" y1="1408" y2="1408" x1="1648" />
            <wire x2="2464" y1="1408" y2="1408" x1="2320" />
            <wire x2="2320" y1="1408" y2="1456" x1="2320" />
            <wire x2="2320" y1="1456" y2="1504" x1="2320" />
        </branch>
        <branch name="led(7:0)">
            <wire x2="2720" y1="1408" y2="1408" x1="2688" />
        </branch>
        <iomarker fontsize="28" x="2720" y="1408" name="led(7:0)" orien="R0" />
        <branch name="anodes(3:0)">
            <wire x2="2288" y1="2416" y2="2416" x1="2064" />
        </branch>
        <branch name="d(15:0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1600" y="1600" type="branch" />
            <wire x2="1600" y1="1600" y2="1792" x1="1600" />
            <wire x2="1680" y1="1792" y2="1792" x1="1600" />
            <wire x2="1680" y1="1792" y2="1808" x1="1680" />
            <wire x2="1616" y1="1600" y2="1600" x1="1600" />
            <wire x2="2320" y1="1600" y2="1600" x1="1616" />
            <wire x2="2544" y1="1600" y2="1600" x1="2320" />
            <wire x2="2784" y1="1600" y2="1600" x1="2544" />
            <wire x2="1680" y1="1808" y2="1808" x1="1600" />
            <wire x2="1600" y1="1808" y2="2096" x1="1600" />
            <wire x2="1680" y1="2096" y2="2096" x1="1600" />
            <wire x2="1680" y1="2096" y2="2112" x1="1680" />
            <wire x2="1680" y1="2112" y2="2112" x1="1664" />
            <wire x2="1664" y1="2112" y2="2352" x1="1664" />
            <wire x2="1680" y1="2352" y2="2352" x1="1664" />
        </branch>
        <bustap x2="2320" y1="1600" y2="1504" x1="2320" />
        <instance x="2400" y="1456" name="XLXI_5" orien="R0">
        </instance>
        <bustap x2="2544" y1="1600" y2="1504" x1="2544" />
        <branch name="d(15:8)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="2544" y="1496" type="branch" />
            <wire x2="2544" y1="1488" y2="1496" x1="2544" />
            <wire x2="2544" y1="1496" y2="1504" x1="2544" />
        </branch>
        <instance x="1680" y="2448" name="XLXI_7" orien="R0">
        </instance>
        <branch name="clk">
            <wire x2="224" y1="192" y2="2080" x1="224" />
            <wire x2="224" y1="2080" y2="2368" x1="224" />
            <wire x2="944" y1="2080" y2="2080" x1="224" />
            <wire x2="944" y1="2080" y2="2480" x1="944" />
            <wire x2="1680" y1="2480" y2="2480" x1="944" />
        </branch>
        <iomarker fontsize="28" x="224" y="192" name="clk" orien="R270" />
        <iomarker fontsize="28" x="2288" y="2416" name="anodes(3:0)" orien="R0" />
        <branch name="sevenseg(6:0)">
            <wire x2="2272" y1="2352" y2="2352" x1="2064" />
        </branch>
        <iomarker fontsize="28" x="2272" y="2352" name="sevenseg(6:0)" orien="R0" />
    </sheet>
</drawing>