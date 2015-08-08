<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="din(15:0)" />
        <signal name="din(3:0)" />
        <signal name="din(7:4)" />
        <signal name="din(11:8)" />
        <signal name="din(15:12)" />
        <signal name="sel(1:0)" />
        <signal name="anodes(3:0)" />
        <signal name="XLXN_53(3:0)" />
        <signal name="sevenseg(6:0)" />
        <signal name="XLXN_55" />
        <signal name="XLXN_56" />
        <signal name="din(3)" />
        <signal name="din(2)" />
        <signal name="din(1)" />
        <signal name="din(0)" />
        <signal name="din(7)" />
        <signal name="din(6)" />
        <signal name="din(5)" />
        <signal name="din(4)" />
        <signal name="din(11)" />
        <signal name="din(10)" />
        <signal name="din(9)" />
        <signal name="din(8)" />
        <signal name="din(15)" />
        <signal name="din(14)" />
        <signal name="din(13)" />
        <signal name="din(12)" />
        <signal name="sel(1)" />
        <signal name="sel(0)" />
        <signal name="XLXN_212" />
        <signal name="clk" />
        <signal name="XLXN_230" />
        <signal name="XLXN_231" />
        <signal name="XLXN_234" />
        <signal name="XLXN_235" />
        <signal name="XLXN_236" />
        <port polarity="Input" name="din(15:0)" />
        <port polarity="Output" name="anodes(3:0)" />
        <port polarity="Output" name="sevenseg(6:0)" />
        <port polarity="Input" name="clk" />
        <blockdef name="Mux4x4">
            <timestamp>2014-9-23T15:22:30</timestamp>
            <rect width="256" x="64" y="-320" height="320" />
            <rect width="64" x="0" y="-300" height="24" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <rect width="64" x="0" y="-236" height="24" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <rect width="64" x="0" y="-172" height="24" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-300" height="24" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
        </blockdef>
        <blockdef name="cb2ce">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <rect width="256" x="64" y="-384" height="320" />
            <line x2="320" y1="-128" y2="-128" x1="384" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="80" y1="-112" y2="-128" x1="64" />
            <line x2="64" y1="-32" y2="-32" x1="192" />
            <line x2="192" y1="-64" y2="-32" x1="192" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="320" y1="-192" y2="-192" x1="384" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <line x2="320" y1="-320" y2="-320" x1="384" />
        </blockdef>
        <blockdef name="enable190">
            <timestamp>2014-9-23T15:18:18</timestamp>
            <rect width="256" x="64" y="-64" height="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="shiftanodes">
            <timestamp>2014-9-23T15:22:53</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <blockdef name="x7seg">
            <timestamp>2014-9-23T16:3:18</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <blockdef name="m4_1e">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="96" y1="-416" y2="-416" x1="0" />
            <line x2="96" y1="-352" y2="-352" x1="0" />
            <line x2="96" y1="-288" y2="-288" x1="0" />
            <line x2="96" y1="-224" y2="-224" x1="0" />
            <line x2="96" y1="-32" y2="-32" x1="0" />
            <line x2="256" y1="-320" y2="-320" x1="320" />
            <line x2="96" y1="-160" y2="-160" x1="0" />
            <line x2="96" y1="-96" y2="-96" x1="0" />
            <line x2="96" y1="-96" y2="-96" x1="176" />
            <line x2="176" y1="-208" y2="-96" x1="176" />
            <line x2="96" y1="-32" y2="-32" x1="224" />
            <line x2="224" y1="-216" y2="-32" x1="224" />
            <line x2="96" y1="-224" y2="-192" x1="256" />
            <line x2="256" y1="-416" y2="-224" x1="256" />
            <line x2="256" y1="-448" y2="-416" x1="96" />
            <line x2="96" y1="-192" y2="-448" x1="96" />
            <line x2="96" y1="-160" y2="-160" x1="128" />
            <line x2="128" y1="-200" y2="-160" x1="128" />
        </blockdef>
        <blockdef name="vcc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-64" x1="64" />
            <line x2="64" y1="0" y2="-32" x1="64" />
            <line x2="32" y1="-64" y2="-64" x1="96" />
        </blockdef>
        <blockdef name="or4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="48" y1="-256" y2="-256" x1="0" />
            <line x2="192" y1="-160" y2="-160" x1="256" />
            <arc ex="112" ey="-208" sx="192" sy="-160" r="88" cx="116" cy="-120" />
            <line x2="48" y1="-208" y2="-208" x1="112" />
            <line x2="48" y1="-112" y2="-112" x1="112" />
            <line x2="48" y1="-256" y2="-208" x1="48" />
            <line x2="48" y1="-64" y2="-112" x1="48" />
            <arc ex="48" ey="-208" sx="48" sy="-112" r="56" cx="16" cy="-160" />
            <arc ex="192" ey="-160" sx="112" sy="-112" r="88" cx="116" cy="-200" />
        </blockdef>
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
        <block symbolname="Mux4x4" name="XLXI_6">
            <blockpin signalname="din(7:4)" name="l1(3:0)" />
            <blockpin signalname="din(11:8)" name="l2(3:0)" />
            <blockpin signalname="din(15:12)" name="l3(3:0)" />
            <blockpin signalname="sel(1:0)" name="S(1:0)" />
            <blockpin signalname="din(3:0)" name="I0(3:0)" />
            <blockpin signalname="XLXN_53(3:0)" name="O(3:0)" />
        </block>
        <block symbolname="cb2ce" name="XLXI_8">
            <blockpin signalname="clk" name="C" />
            <blockpin signalname="XLXN_212" name="CE" />
            <blockpin name="CLR" />
            <blockpin name="CEO" />
            <blockpin signalname="sel(0)" name="Q0" />
            <blockpin signalname="sel(1)" name="Q1" />
            <blockpin name="TC" />
        </block>
        <block symbolname="enable190" name="XLXI_11">
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="XLXN_212" name="enable190" />
        </block>
        <block symbolname="shiftanodes" name="XLXI_13">
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="XLXN_212" name="enable190" />
            <blockpin signalname="anodes(3:0)" name="anodes(3:0)" />
        </block>
        <block symbolname="x7seg" name="XLXI_16">
            <blockpin signalname="XLXN_55" name="e" />
            <blockpin signalname="XLXN_53(3:0)" name="sw(3:0)" />
            <blockpin signalname="sevenseg(6:0)" name="sevenseg(6:0)" />
        </block>
        <block symbolname="m4_1e" name="XLXI_17">
            <blockpin signalname="XLXN_236" name="D0" />
            <blockpin signalname="XLXN_235" name="D1" />
            <blockpin signalname="XLXN_230" name="D2" />
            <blockpin signalname="XLXN_231" name="D3" />
            <blockpin signalname="XLXN_56" name="E" />
            <blockpin signalname="sel(0)" name="S0" />
            <blockpin signalname="sel(1)" name="S1" />
            <blockpin signalname="XLXN_55" name="O" />
        </block>
        <block symbolname="vcc" name="XLXI_18">
            <blockpin signalname="XLXN_56" name="P" />
        </block>
        <block symbolname="or4" name="XLXI_27">
            <blockpin signalname="din(3)" name="I0" />
            <blockpin signalname="din(2)" name="I1" />
            <blockpin signalname="din(1)" name="I2" />
            <blockpin signalname="din(0)" name="I3" />
            <blockpin signalname="XLXN_234" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_28">
            <blockpin signalname="din(7)" name="I0" />
            <blockpin signalname="din(6)" name="I1" />
            <blockpin signalname="din(5)" name="I2" />
            <blockpin signalname="din(4)" name="I3" />
            <blockpin signalname="XLXN_235" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_29">
            <blockpin signalname="din(11)" name="I0" />
            <blockpin signalname="din(10)" name="I1" />
            <blockpin signalname="din(9)" name="I2" />
            <blockpin signalname="din(8)" name="I3" />
            <blockpin signalname="XLXN_230" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_30">
            <blockpin signalname="din(15)" name="I0" />
            <blockpin signalname="din(14)" name="I1" />
            <blockpin signalname="din(13)" name="I2" />
            <blockpin signalname="din(12)" name="I3" />
            <blockpin signalname="XLXN_231" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_38">
            <blockpin signalname="XLXN_235" name="I0" />
            <blockpin signalname="XLXN_234" name="I1" />
            <blockpin signalname="XLXN_236" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="din(15:0)">
            <wire x2="432" y1="512" y2="656" x1="432" />
            <wire x2="432" y1="656" y2="720" x1="432" />
            <wire x2="432" y1="720" y2="784" x1="432" />
            <wire x2="432" y1="784" y2="912" x1="432" />
            <wire x2="432" y1="912" y2="1952" x1="432" />
        </branch>
        <bustap x2="528" y1="912" y2="912" x1="432" />
        <branch name="din(3:0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="824" y="912" type="branch" />
            <wire x2="544" y1="912" y2="912" x1="528" />
            <wire x2="608" y1="912" y2="912" x1="544" />
            <wire x2="672" y1="912" y2="912" x1="608" />
            <wire x2="736" y1="912" y2="912" x1="672" />
            <wire x2="824" y1="912" y2="912" x1="736" />
            <wire x2="1504" y1="912" y2="912" x1="824" />
        </branch>
        <bustap x2="528" y1="656" y2="656" x1="432" />
        <branch name="din(7:4)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="824" y="656" type="branch" />
            <wire x2="768" y1="656" y2="656" x1="528" />
            <wire x2="824" y1="656" y2="656" x1="768" />
            <wire x2="832" y1="656" y2="656" x1="824" />
            <wire x2="896" y1="656" y2="656" x1="832" />
            <wire x2="960" y1="656" y2="656" x1="896" />
            <wire x2="1504" y1="656" y2="656" x1="960" />
        </branch>
        <bustap x2="528" y1="720" y2="720" x1="432" />
        <branch name="din(11:8)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="824" y="720" type="branch" />
            <wire x2="824" y1="720" y2="720" x1="528" />
            <wire x2="1008" y1="720" y2="720" x1="824" />
            <wire x2="1072" y1="720" y2="720" x1="1008" />
            <wire x2="1136" y1="720" y2="720" x1="1072" />
            <wire x2="1200" y1="720" y2="720" x1="1136" />
            <wire x2="1504" y1="720" y2="720" x1="1200" />
        </branch>
        <bustap x2="528" y1="784" y2="784" x1="432" />
        <branch name="din(15:12)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="824" y="784" type="branch" />
            <wire x2="824" y1="784" y2="784" x1="528" />
            <wire x2="1248" y1="784" y2="784" x1="824" />
            <wire x2="1312" y1="784" y2="784" x1="1248" />
            <wire x2="1376" y1="784" y2="784" x1="1312" />
            <wire x2="1440" y1="784" y2="784" x1="1376" />
            <wire x2="1504" y1="784" y2="784" x1="1440" />
        </branch>
        <instance x="640" y="1392" name="XLXI_8" orien="R0" />
        <branch name="sel(1:0)">
            <wire x2="1504" y1="848" y2="848" x1="1280" />
            <wire x2="1280" y1="848" y2="1072" x1="1280" />
            <wire x2="1280" y1="1072" y2="1136" x1="1280" />
            <wire x2="1280" y1="1136" y2="1200" x1="1280" />
            <wire x2="1472" y1="1200" y2="1200" x1="1280" />
        </branch>
        <branch name="anodes(3:0)">
            <wire x2="2096" y1="1360" y2="1360" x1="1872" />
        </branch>
        <instance x="640" y="1648" name="XLXI_11" orien="R0">
        </instance>
        <instance x="1488" y="1456" name="XLXI_13" orien="R0">
        </instance>
        <instance x="2320" y="752" name="XLXI_16" orien="R0">
        </instance>
        <branch name="XLXN_53(3:0)">
            <wire x2="2096" y1="656" y2="656" x1="1888" />
            <wire x2="2096" y1="656" y2="720" x1="2096" />
            <wire x2="2320" y1="720" y2="720" x1="2096" />
        </branch>
        <branch name="sevenseg(6:0)">
            <wire x2="2992" y1="656" y2="656" x1="2704" />
        </branch>
        <iomarker fontsize="28" x="2992" y="656" name="sevenseg(6:0)" orien="R0" />
        <branch name="XLXN_55">
            <wire x2="2320" y1="656" y2="656" x1="2304" />
            <wire x2="2304" y1="656" y2="816" x1="2304" />
            <wire x2="2768" y1="816" y2="816" x1="2304" />
            <wire x2="2768" y1="208" y2="208" x1="2496" />
            <wire x2="2768" y1="208" y2="816" x1="2768" />
        </branch>
        <iomarker fontsize="28" x="432" y="512" name="din(15:0)" orien="R270" />
        <instance x="2128" y="592" name="XLXI_18" orien="R0" />
        <instance x="1504" y="944" name="XLXI_6" orien="R0">
        </instance>
        <bustap x2="736" y1="912" y2="816" x1="736" />
        <branch name="din(3)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="736" y="704" type="branch" />
            <wire x2="736" y1="544" y2="704" x1="736" />
            <wire x2="736" y1="704" y2="816" x1="736" />
        </branch>
        <bustap x2="672" y1="912" y2="816" x1="672" />
        <branch name="din(2)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="672" y="704" type="branch" />
            <wire x2="672" y1="544" y2="704" x1="672" />
            <wire x2="672" y1="704" y2="816" x1="672" />
        </branch>
        <bustap x2="608" y1="912" y2="816" x1="608" />
        <branch name="din(1)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="608" y="704" type="branch" />
            <wire x2="608" y1="544" y2="704" x1="608" />
            <wire x2="608" y1="704" y2="816" x1="608" />
        </branch>
        <bustap x2="544" y1="912" y2="816" x1="544" />
        <branch name="din(0)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="544" y="704" type="branch" />
            <wire x2="544" y1="544" y2="704" x1="544" />
            <wire x2="544" y1="704" y2="816" x1="544" />
        </branch>
        <instance x="1024" y="544" name="XLXI_28" orien="R270" />
        <bustap x2="960" y1="656" y2="560" x1="960" />
        <branch name="din(7)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="960" y="552" type="branch" />
            <wire x2="960" y1="544" y2="552" x1="960" />
            <wire x2="960" y1="552" y2="560" x1="960" />
        </branch>
        <bustap x2="896" y1="656" y2="560" x1="896" />
        <branch name="din(6)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="896" y="552" type="branch" />
            <wire x2="896" y1="544" y2="552" x1="896" />
            <wire x2="896" y1="552" y2="560" x1="896" />
        </branch>
        <bustap x2="832" y1="656" y2="560" x1="832" />
        <branch name="din(5)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="832" y="552" type="branch" />
            <wire x2="832" y1="544" y2="552" x1="832" />
            <wire x2="832" y1="552" y2="560" x1="832" />
        </branch>
        <bustap x2="768" y1="656" y2="560" x1="768" />
        <branch name="din(4)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="768" y="552" type="branch" />
            <wire x2="768" y1="544" y2="552" x1="768" />
            <wire x2="768" y1="552" y2="560" x1="768" />
        </branch>
        <instance x="1264" y="544" name="XLXI_29" orien="R270" />
        <bustap x2="1200" y1="720" y2="624" x1="1200" />
        <branch name="din(11)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="1200" y="584" type="branch" />
            <wire x2="1200" y1="544" y2="584" x1="1200" />
            <wire x2="1200" y1="584" y2="624" x1="1200" />
        </branch>
        <bustap x2="1136" y1="720" y2="624" x1="1136" />
        <branch name="din(10)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="1136" y="584" type="branch" />
            <wire x2="1136" y1="544" y2="584" x1="1136" />
            <wire x2="1136" y1="584" y2="624" x1="1136" />
        </branch>
        <bustap x2="1072" y1="720" y2="624" x1="1072" />
        <branch name="din(9)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="1072" y="584" type="branch" />
            <wire x2="1072" y1="544" y2="584" x1="1072" />
            <wire x2="1072" y1="584" y2="624" x1="1072" />
        </branch>
        <bustap x2="1008" y1="720" y2="624" x1="1008" />
        <branch name="din(8)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="1008" y="584" type="branch" />
            <wire x2="1008" y1="544" y2="584" x1="1008" />
            <wire x2="1008" y1="584" y2="624" x1="1008" />
        </branch>
        <bustap x2="1440" y1="784" y2="688" x1="1440" />
        <branch name="din(15)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="1440" y="640" type="branch" />
            <wire x2="1440" y1="576" y2="640" x1="1440" />
            <wire x2="1440" y1="640" y2="688" x1="1440" />
        </branch>
        <bustap x2="1376" y1="784" y2="688" x1="1376" />
        <branch name="din(14)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="1376" y="640" type="branch" />
            <wire x2="1376" y1="576" y2="640" x1="1376" />
            <wire x2="1376" y1="640" y2="688" x1="1376" />
        </branch>
        <bustap x2="1312" y1="784" y2="688" x1="1312" />
        <branch name="din(13)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="1312" y="640" type="branch" />
            <wire x2="1312" y1="576" y2="640" x1="1312" />
            <wire x2="1312" y1="640" y2="688" x1="1312" />
        </branch>
        <bustap x2="1248" y1="784" y2="688" x1="1248" />
        <branch name="din(12)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="1248" y="640" type="branch" />
            <wire x2="1248" y1="576" y2="640" x1="1248" />
            <wire x2="1248" y1="640" y2="688" x1="1248" />
        </branch>
        <bustap x2="1184" y1="1136" y2="1136" x1="1280" />
        <branch name="sel(1)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1104" y="1136" type="branch" />
            <wire x2="1040" y1="1136" y2="1136" x1="1024" />
            <wire x2="1104" y1="1136" y2="1136" x1="1040" />
            <wire x2="1184" y1="1136" y2="1136" x1="1104" />
            <wire x2="1040" y1="1136" y2="1168" x1="1040" />
            <wire x2="1952" y1="1168" y2="1168" x1="1040" />
            <wire x2="1952" y1="432" y2="1168" x1="1952" />
            <wire x2="2176" y1="432" y2="432" x1="1952" />
        </branch>
        <bustap x2="1184" y1="1072" y2="1072" x1="1280" />
        <branch name="sel(0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1104" y="1072" type="branch" />
            <wire x2="1104" y1="1072" y2="1072" x1="1024" />
            <wire x2="1152" y1="1072" y2="1072" x1="1104" />
            <wire x2="1184" y1="1072" y2="1072" x1="1152" />
            <wire x2="1152" y1="1072" y2="1104" x1="1152" />
            <wire x2="1488" y1="1104" y2="1104" x1="1152" />
            <wire x2="1488" y1="368" y2="1104" x1="1488" />
            <wire x2="2176" y1="368" y2="368" x1="1488" />
        </branch>
        <branch name="XLXN_212">
            <wire x2="640" y1="1200" y2="1200" x1="576" />
            <wire x2="576" y1="1200" y2="1424" x1="576" />
            <wire x2="1088" y1="1424" y2="1424" x1="576" />
            <wire x2="1088" y1="1424" y2="1456" x1="1088" />
            <wire x2="1088" y1="1456" y2="1616" x1="1088" />
            <wire x2="1280" y1="1456" y2="1456" x1="1088" />
            <wire x2="1088" y1="1616" y2="1616" x1="1024" />
            <wire x2="1280" y1="1424" y2="1456" x1="1280" />
            <wire x2="1488" y1="1424" y2="1424" x1="1280" />
        </branch>
        <branch name="clk">
            <wire x2="160" y1="544" y2="1264" x1="160" />
            <wire x2="160" y1="1264" y2="1616" x1="160" />
            <wire x2="640" y1="1616" y2="1616" x1="160" />
            <wire x2="160" y1="1616" y2="2016" x1="160" />
            <wire x2="1040" y1="2016" y2="2016" x1="160" />
            <wire x2="640" y1="1264" y2="1264" x1="160" />
            <wire x2="1488" y1="1360" y2="1360" x1="1040" />
            <wire x2="1040" y1="1360" y2="2016" x1="1040" />
        </branch>
        <iomarker fontsize="28" x="160" y="544" name="clk" orien="R270" />
        <instance x="2176" y="528" name="XLXI_17" orien="R0" />
        <branch name="XLXN_56">
            <wire x2="2176" y1="496" y2="496" x1="2144" />
            <wire x2="2144" y1="496" y2="608" x1="2144" />
            <wire x2="2192" y1="608" y2="608" x1="2144" />
            <wire x2="2192" y1="592" y2="608" x1="2192" />
        </branch>
        <instance x="800" y="544" name="XLXI_27" orien="R270" />
        <instance x="1504" y="576" name="XLXI_30" orien="R270" />
        <branch name="XLXN_230">
            <wire x2="2176" y1="240" y2="240" x1="1104" />
            <wire x2="1104" y1="240" y2="288" x1="1104" />
        </branch>
        <branch name="XLXN_231">
            <wire x2="2176" y1="304" y2="304" x1="1344" />
            <wire x2="1344" y1="304" y2="320" x1="1344" />
        </branch>
        <iomarker fontsize="28" x="2096" y="1360" name="anodes(3:0)" orien="R0" />
        <branch name="XLXN_236">
            <wire x2="2176" y1="112" y2="112" x1="1440" />
        </branch>
        <instance x="1184" y="208" name="XLXI_38" orien="R0" />
        <branch name="XLXN_234">
            <wire x2="1184" y1="80" y2="80" x1="640" />
            <wire x2="640" y1="80" y2="288" x1="640" />
        </branch>
        <branch name="XLXN_235">
            <wire x2="864" y1="176" y2="288" x1="864" />
            <wire x2="1120" y1="176" y2="176" x1="864" />
            <wire x2="2176" y1="176" y2="176" x1="1120" />
            <wire x2="1184" y1="144" y2="144" x1="1120" />
            <wire x2="1120" y1="144" y2="176" x1="1120" />
        </branch>
    </sheet>
</drawing>