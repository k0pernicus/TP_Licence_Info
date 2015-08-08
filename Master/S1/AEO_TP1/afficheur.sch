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
        <signal name="sel(1)" />
        <signal name="sel(0)" />
        <signal name="XLXN_41(3:0)" />
        <signal name="sevenseg(6:0)" />
        <signal name="clk" />
        <signal name="anodes(3:0)" />
        <signal name="XLXN_52" />
        <port polarity="Input" name="din(15:0)" />
        <port polarity="Output" name="sevenseg(6:0)" />
        <port polarity="Input" name="clk" />
        <port polarity="Output" name="anodes(3:0)" />
        <blockdef name="x7seg">
            <timestamp>2014-9-16T16:8:23</timestamp>
            <rect width="256" x="64" y="-64" height="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
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
        <block symbolname="Mux4x4" name="XLXI_6">
            <blockpin signalname="din(7:4)" name="l1(3:0)" />
            <blockpin signalname="din(11:8)" name="l2(3:0)" />
            <blockpin signalname="din(15:12)" name="l3(3:0)" />
            <blockpin signalname="sel(1:0)" name="S(1:0)" />
            <blockpin signalname="din(3:0)" name="I0(3:0)" />
            <blockpin signalname="XLXN_41(3:0)" name="O(3:0)" />
        </block>
        <block symbolname="cb2ce" name="XLXI_8">
            <blockpin signalname="clk" name="C" />
            <blockpin signalname="XLXN_52" name="CE" />
            <blockpin name="CLR" />
            <blockpin name="CEO" />
            <blockpin signalname="sel(0)" name="Q0" />
            <blockpin signalname="sel(1)" name="Q1" />
            <blockpin name="TC" />
        </block>
        <block symbolname="enable190" name="XLXI_11">
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="XLXN_52" name="enable190" />
        </block>
        <block symbolname="x7seg" name="XLXI_12">
            <blockpin signalname="XLXN_41(3:0)" name="sw(3:0)" />
            <blockpin signalname="sevenseg(6:0)" name="sevenseg(6:0)" />
        </block>
        <block symbolname="shiftanodes" name="XLXI_13">
            <blockpin signalname="XLXN_52" name="clk" />
            <blockpin signalname="clk" name="enable190" />
            <blockpin signalname="anodes(3:0)" name="anodes(3:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="din(15:0)">
            <wire x2="432" y1="256" y2="656" x1="432" />
            <wire x2="432" y1="656" y2="720" x1="432" />
            <wire x2="432" y1="720" y2="784" x1="432" />
            <wire x2="432" y1="784" y2="912" x1="432" />
            <wire x2="432" y1="912" y2="1952" x1="432" />
        </branch>
        <iomarker fontsize="28" x="432" y="256" name="din(15:0)" orien="R270" />
        <bustap x2="528" y1="912" y2="912" x1="432" />
        <branch name="din(3:0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="824" y="912" type="branch" />
            <wire x2="824" y1="912" y2="912" x1="528" />
            <wire x2="1376" y1="912" y2="912" x1="824" />
        </branch>
        <bustap x2="528" y1="656" y2="656" x1="432" />
        <branch name="din(7:4)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="824" y="656" type="branch" />
            <wire x2="824" y1="656" y2="656" x1="528" />
            <wire x2="1376" y1="656" y2="656" x1="824" />
        </branch>
        <bustap x2="528" y1="720" y2="720" x1="432" />
        <branch name="din(11:8)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="824" y="720" type="branch" />
            <wire x2="824" y1="720" y2="720" x1="528" />
            <wire x2="1376" y1="720" y2="720" x1="824" />
        </branch>
        <bustap x2="528" y1="784" y2="784" x1="432" />
        <branch name="din(15:12)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="824" y="784" type="branch" />
            <wire x2="824" y1="784" y2="784" x1="528" />
            <wire x2="1376" y1="784" y2="784" x1="824" />
        </branch>
        <instance x="640" y="1392" name="XLXI_8" orien="R0" />
        <instance x="1376" y="944" name="XLXI_6" orien="R0">
        </instance>
        <branch name="sel(1:0)">
            <wire x2="1376" y1="848" y2="848" x1="1360" />
            <wire x2="1360" y1="848" y2="1072" x1="1360" />
            <wire x2="1360" y1="1072" y2="1136" x1="1360" />
            <wire x2="1360" y1="1136" y2="1200" x1="1360" />
            <wire x2="1472" y1="1200" y2="1200" x1="1360" />
        </branch>
        <bustap x2="1264" y1="1136" y2="1136" x1="1360" />
        <branch name="sel(1)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1144" y="1136" type="branch" />
            <wire x2="1144" y1="1136" y2="1136" x1="1024" />
            <wire x2="1264" y1="1136" y2="1136" x1="1144" />
        </branch>
        <bustap x2="1264" y1="1072" y2="1072" x1="1360" />
        <branch name="sel(0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1144" y="1072" type="branch" />
            <wire x2="1144" y1="1072" y2="1072" x1="1024" />
            <wire x2="1264" y1="1072" y2="1072" x1="1144" />
        </branch>
        <branch name="XLXN_41(3:0)">
            <wire x2="2288" y1="656" y2="656" x1="1760" />
            <wire x2="2288" y1="560" y2="560" x1="2224" />
            <wire x2="2224" y1="560" y2="640" x1="2224" />
            <wire x2="2288" y1="640" y2="640" x1="2224" />
            <wire x2="2288" y1="640" y2="656" x1="2288" />
        </branch>
        <branch name="sevenseg(6:0)">
            <wire x2="2736" y1="560" y2="560" x1="2672" />
            <wire x2="2736" y1="560" y2="608" x1="2736" />
            <wire x2="2736" y1="608" y2="608" x1="2672" />
            <wire x2="2672" y1="608" y2="656" x1="2672" />
            <wire x2="2704" y1="656" y2="656" x1="2672" />
        </branch>
        <iomarker fontsize="28" x="2704" y="656" name="sevenseg(6:0)" orien="R0" />
        <branch name="clk">
            <wire x2="160" y1="672" y2="1264" x1="160" />
            <wire x2="640" y1="1264" y2="1264" x1="160" />
            <wire x2="160" y1="1264" y2="1552" x1="160" />
            <wire x2="160" y1="1552" y2="1920" x1="160" />
            <wire x2="1072" y1="1920" y2="1920" x1="160" />
            <wire x2="640" y1="1552" y2="1552" x1="160" />
            <wire x2="544" y1="1536" y2="1616" x1="544" />
            <wire x2="640" y1="1616" y2="1616" x1="544" />
            <wire x2="640" y1="1536" y2="1536" x1="544" />
            <wire x2="640" y1="1536" y2="1552" x1="640" />
            <wire x2="1072" y1="1584" y2="1920" x1="1072" />
            <wire x2="1456" y1="1584" y2="1584" x1="1072" />
            <wire x2="1456" y1="1424" y2="1584" x1="1456" />
            <wire x2="1488" y1="1424" y2="1424" x1="1456" />
        </branch>
        <iomarker fontsize="28" x="160" y="672" name="clk" orien="R270" />
        <branch name="anodes(3:0)">
            <wire x2="2896" y1="1520" y2="1520" x1="1856" />
            <wire x2="1856" y1="1520" y2="1536" x1="1856" />
            <wire x2="1952" y1="1536" y2="1536" x1="1856" />
            <wire x2="1952" y1="1360" y2="1360" x1="1872" />
            <wire x2="1952" y1="1360" y2="1536" x1="1952" />
        </branch>
        <iomarker fontsize="28" x="2896" y="1520" name="anodes(3:0)" orien="R0" />
        <instance x="640" y="1648" name="XLXI_11" orien="R0">
        </instance>
        <instance x="2288" y="592" name="XLXI_12" orien="R0">
        </instance>
        <instance x="1488" y="1456" name="XLXI_13" orien="R0">
        </instance>
        <branch name="XLXN_52">
            <wire x2="560" y1="928" y2="1200" x1="560" />
            <wire x2="640" y1="1200" y2="1200" x1="560" />
            <wire x2="1088" y1="928" y2="928" x1="560" />
            <wire x2="1088" y1="928" y2="1488" x1="1088" />
            <wire x2="1088" y1="1488" y2="1552" x1="1088" />
            <wire x2="1280" y1="1488" y2="1488" x1="1088" />
            <wire x2="1280" y1="1488" y2="1520" x1="1280" />
            <wire x2="1472" y1="1520" y2="1520" x1="1280" />
            <wire x2="1088" y1="1552" y2="1552" x1="1024" />
            <wire x2="1024" y1="1552" y2="1568" x1="1024" />
            <wire x2="1040" y1="1568" y2="1568" x1="1024" />
            <wire x2="1040" y1="1568" y2="1616" x1="1040" />
            <wire x2="1040" y1="1616" y2="1616" x1="1024" />
            <wire x2="1488" y1="1360" y2="1360" x1="1472" />
            <wire x2="1472" y1="1360" y2="1520" x1="1472" />
        </branch>
    </sheet>
</drawing>