<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_2" />
        <signal name="clk190" />
        <signal name="clk" />
        <signal name="XLXN_7" />
        <signal name="XLXN_13" />
        <signal name="XLXN_14" />
        <signal name="enable190" />
        <signal name="XLXN_33" />
        <port polarity="Input" name="clk" />
        <port polarity="Output" name="enable190" />
        <blockdef name="cb16ce">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="320" y1="-192" y2="-192" x1="384" />
            <rect width="64" x="320" y="-268" height="24" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="64" y1="-32" y2="-32" x1="192" />
            <line x2="192" y1="-64" y2="-32" x1="192" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="80" y1="-112" y2="-128" x1="64" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="320" y1="-128" y2="-128" x1="384" />
            <rect width="256" x="64" y="-320" height="256" />
        </blockdef>
        <blockdef name="cb4ce">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <rect width="256" x="64" y="-512" height="448" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <line x2="320" y1="-320" y2="-320" x1="384" />
            <line x2="320" y1="-384" y2="-384" x1="384" />
            <line x2="320" y1="-448" y2="-448" x1="384" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="80" y1="-112" y2="-128" x1="64" />
            <line x2="320" y1="-128" y2="-128" x1="384" />
            <line x2="64" y1="-32" y2="-32" x1="192" />
            <line x2="192" y1="-64" y2="-32" x1="192" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="320" y1="-192" y2="-192" x1="384" />
        </blockdef>
        <blockdef name="vcc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-64" x1="64" />
            <line x2="64" y1="0" y2="-32" x1="64" />
            <line x2="32" y1="-64" y2="-64" x1="96" />
        </blockdef>
        <blockdef name="fd">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <rect width="256" x="64" y="-320" height="256" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="80" y1="-112" y2="-128" x1="64" />
        </blockdef>
        <blockdef name="nor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="216" y1="-96" y2="-96" x1="256" />
            <circle r="12" cx="204" cy="-96" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
        </blockdef>
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <block symbolname="cb16ce" name="XLXI_1">
            <blockpin signalname="clk" name="C" />
            <blockpin signalname="XLXN_2" name="CE" />
            <blockpin name="CLR" />
            <blockpin signalname="XLXN_7" name="CEO" />
            <blockpin name="Q(15:0)" />
            <blockpin name="TC" />
        </block>
        <block symbolname="cb4ce" name="XLXI_2">
            <blockpin signalname="clk" name="C" />
            <blockpin signalname="XLXN_7" name="CE" />
            <blockpin name="CLR" />
            <blockpin name="CEO" />
            <blockpin name="Q0" />
            <blockpin name="Q1" />
            <blockpin signalname="clk190" name="Q2" />
            <blockpin name="Q3" />
            <blockpin name="TC" />
        </block>
        <block symbolname="vcc" name="XLXI_3">
            <blockpin signalname="XLXN_2" name="P" />
        </block>
        <block symbolname="fd" name="XLXI_4">
            <blockpin signalname="clk" name="C" />
            <blockpin signalname="clk190" name="D" />
            <blockpin signalname="XLXN_33" name="Q" />
        </block>
        <block symbolname="fd" name="XLXI_5">
            <blockpin signalname="clk" name="C" />
            <blockpin signalname="XLXN_33" name="D" />
            <blockpin signalname="XLXN_13" name="Q" />
        </block>
        <block symbolname="nor2" name="XLXI_7">
            <blockpin signalname="XLXN_13" name="I0" />
            <blockpin signalname="XLXN_14" name="I1" />
            <blockpin signalname="enable190" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_8">
            <blockpin signalname="XLXN_33" name="I" />
            <blockpin signalname="XLXN_14" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="clk190">
            <wire x2="1584" y1="848" y2="848" x1="1408" />
        </branch>
        <branch name="clk">
            <wire x2="624" y1="1264" y2="1264" x1="160" />
            <wire x2="832" y1="1264" y2="1264" x1="624" />
            <wire x2="1888" y1="1264" y2="1264" x1="832" />
            <wire x2="2080" y1="1264" y2="1264" x1="1888" />
            <wire x2="400" y1="1040" y2="1040" x1="336" />
            <wire x2="336" y1="1040" y2="1200" x1="336" />
            <wire x2="624" y1="1200" y2="1200" x1="336" />
            <wire x2="624" y1="1200" y2="1264" x1="624" />
            <wire x2="1024" y1="1040" y2="1040" x1="832" />
            <wire x2="832" y1="1040" y2="1264" x1="832" />
            <wire x2="1584" y1="976" y2="976" x1="1520" />
            <wire x2="1520" y1="976" y2="1120" x1="1520" />
            <wire x2="1888" y1="1120" y2="1120" x1="1520" />
            <wire x2="1888" y1="1120" y2="1264" x1="1888" />
            <wire x2="2080" y1="1088" y2="1264" x1="2080" />
            <wire x2="2288" y1="1088" y2="1088" x1="2080" />
        </branch>
        <branch name="XLXN_7">
            <wire x2="1024" y1="976" y2="976" x1="784" />
        </branch>
        <branch name="enable190">
            <wire x2="3264" y1="848" y2="848" x1="3216" />
        </branch>
        <instance x="128" y="960" name="XLXI_3" orien="R0" />
        <branch name="XLXN_2">
            <wire x2="192" y1="960" y2="976" x1="192" />
            <wire x2="400" y1="976" y2="976" x1="192" />
        </branch>
        <instance x="400" y="1168" name="XLXI_1" orien="R0" />
        <iomarker fontsize="28" x="160" y="1264" name="clk" orien="R180" />
        <instance x="1024" y="1168" name="XLXI_2" orien="R0" />
        <instance x="1584" y="1104" name="XLXI_4" orien="R0" />
        <instance x="2288" y="1216" name="XLXI_5" orien="R0" />
        <branch name="XLXN_14">
            <wire x2="2944" y1="624" y2="624" x1="2608" />
            <wire x2="2944" y1="624" y2="816" x1="2944" />
            <wire x2="2960" y1="816" y2="816" x1="2944" />
        </branch>
        <instance x="2960" y="944" name="XLXI_7" orien="R0" />
        <branch name="XLXN_13">
            <wire x2="2688" y1="960" y2="960" x1="2672" />
            <wire x2="2960" y1="880" y2="880" x1="2688" />
            <wire x2="2688" y1="880" y2="960" x1="2688" />
        </branch>
        <iomarker fontsize="28" x="3264" y="848" name="enable190" orien="R0" />
        <instance x="2384" y="656" name="XLXI_8" orien="R0" />
        <branch name="XLXN_33">
            <wire x2="2128" y1="848" y2="848" x1="1968" />
            <wire x2="2128" y1="848" y2="960" x1="2128" />
            <wire x2="2288" y1="960" y2="960" x1="2128" />
            <wire x2="2384" y1="624" y2="624" x1="2128" />
            <wire x2="2128" y1="624" y2="848" x1="2128" />
        </branch>
    </sheet>
</drawing>