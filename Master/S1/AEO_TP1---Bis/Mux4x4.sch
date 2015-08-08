<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="l1(3:0)" />
        <signal name="l2(3:0)" />
        <signal name="l3(3:0)" />
        <signal name="S(1:0)" />
        <signal name="O(3:0)" />
        <signal name="I0(3:0)" />
        <signal name="XLXN_52" />
        <signal name="I0(3)" />
        <signal name="I0(2)" />
        <signal name="I0(1)" />
        <signal name="I0(0)" />
        <signal name="l1(3)" />
        <signal name="l1(2)" />
        <signal name="l1(1)" />
        <signal name="l1(0)" />
        <signal name="l2(3)" />
        <signal name="l2(2)" />
        <signal name="l2(1)" />
        <signal name="l2(0)" />
        <signal name="l3(3)" />
        <signal name="l3(2)" />
        <signal name="l3(1)" />
        <signal name="l3(0)" />
        <signal name="S(1)" />
        <signal name="S(0)" />
        <signal name="O(3)" />
        <signal name="O(2)" />
        <signal name="O(1)" />
        <signal name="O(0)" />
        <port polarity="Input" name="l1(3:0)" />
        <port polarity="Input" name="l2(3:0)" />
        <port polarity="Input" name="l3(3:0)" />
        <port polarity="Input" name="S(1:0)" />
        <port polarity="Output" name="O(3:0)" />
        <port polarity="Input" name="I0(3:0)" />
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
        <block symbolname="m4_1e" name="XLXI_2">
            <blockpin signalname="I0(2)" name="D0" />
            <blockpin signalname="l1(2)" name="D1" />
            <blockpin signalname="l2(2)" name="D2" />
            <blockpin signalname="l3(2)" name="D3" />
            <blockpin signalname="XLXN_52" name="E" />
            <blockpin signalname="S(0)" name="S0" />
            <blockpin signalname="S(1)" name="S1" />
            <blockpin signalname="O(2)" name="O" />
        </block>
        <block symbolname="m4_1e" name="XLXI_3">
            <blockpin signalname="I0(1)" name="D0" />
            <blockpin signalname="l1(1)" name="D1" />
            <blockpin signalname="l2(1)" name="D2" />
            <blockpin signalname="l3(1)" name="D3" />
            <blockpin signalname="XLXN_52" name="E" />
            <blockpin signalname="S(0)" name="S0" />
            <blockpin signalname="S(1)" name="S1" />
            <blockpin signalname="O(1)" name="O" />
        </block>
        <block symbolname="m4_1e" name="XLXI_4">
            <blockpin signalname="I0(0)" name="D0" />
            <blockpin signalname="l1(0)" name="D1" />
            <blockpin signalname="l2(0)" name="D2" />
            <blockpin signalname="l3(0)" name="D3" />
            <blockpin signalname="XLXN_52" name="E" />
            <blockpin signalname="S(0)" name="S0" />
            <blockpin signalname="S(1)" name="S1" />
            <blockpin signalname="O(0)" name="O" />
        </block>
        <block symbolname="m4_1e" name="XLXI_5">
            <blockpin signalname="I0(3)" name="D0" />
            <blockpin signalname="l1(3)" name="D1" />
            <blockpin signalname="l2(3)" name="D2" />
            <blockpin signalname="l3(3)" name="D3" />
            <blockpin signalname="XLXN_52" name="E" />
            <blockpin signalname="S(0)" name="S0" />
            <blockpin signalname="S(1)" name="S1" />
            <blockpin signalname="O(3)" name="O" />
        </block>
        <block symbolname="vcc" name="XLXI_6">
            <blockpin signalname="XLXN_52" name="P" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="l1(3:0)">
            <wire x2="848" y1="528" y2="640" x1="848" />
            <wire x2="848" y1="640" y2="656" x1="848" />
            <wire x2="848" y1="656" y2="688" x1="848" />
            <wire x2="848" y1="688" y2="1152" x1="848" />
            <wire x2="848" y1="1152" y2="1584" x1="848" />
            <wire x2="848" y1="1584" y2="2032" x1="848" />
            <wire x2="848" y1="2032" y2="2656" x1="848" />
        </branch>
        <branch name="l2(3:0)">
            <wire x2="1024" y1="528" y2="704" x1="1024" />
            <wire x2="1024" y1="704" y2="720" x1="1024" />
            <wire x2="1024" y1="720" y2="1216" x1="1024" />
            <wire x2="1024" y1="1216" y2="1648" x1="1024" />
            <wire x2="1024" y1="1648" y2="2096" x1="1024" />
            <wire x2="1024" y1="2096" y2="2656" x1="1024" />
        </branch>
        <branch name="l3(3:0)">
            <wire x2="1200" y1="528" y2="768" x1="1200" />
            <wire x2="1200" y1="768" y2="784" x1="1200" />
            <wire x2="1200" y1="784" y2="800" x1="1200" />
            <wire x2="1200" y1="800" y2="976" x1="1200" />
            <wire x2="1200" y1="976" y2="1280" x1="1200" />
            <wire x2="1200" y1="1280" y2="1712" x1="1200" />
            <wire x2="1200" y1="1712" y2="2160" x1="1200" />
            <wire x2="1200" y1="2160" y2="2352" x1="1200" />
            <wire x2="1200" y1="2352" y2="2656" x1="1200" />
        </branch>
        <branch name="O(3:0)">
            <wire x2="2656" y1="608" y2="688" x1="2656" />
            <wire x2="2656" y1="688" y2="1184" x1="2656" />
            <wire x2="2656" y1="1184" y2="1616" x1="2656" />
            <wire x2="2656" y1="1616" y2="2064" x1="2656" />
            <wire x2="2656" y1="2064" y2="2080" x1="2656" />
            <wire x2="2656" y1="2080" y2="2496" x1="2656" />
        </branch>
        <branch name="I0(3:0)">
            <wire x2="688" y1="528" y2="592" x1="688" />
            <wire x2="688" y1="592" y2="1072" x1="688" />
            <wire x2="688" y1="1072" y2="1088" x1="688" />
            <wire x2="688" y1="1088" y2="1520" x1="688" />
            <wire x2="688" y1="1520" y2="1968" x1="688" />
            <wire x2="688" y1="1968" y2="2656" x1="688" />
        </branch>
        <instance x="1584" y="1504" name="XLXI_2" orien="R0" />
        <instance x="1584" y="1936" name="XLXI_3" orien="R0" />
        <instance x="1584" y="1008" name="XLXI_5" orien="R0" />
        <iomarker fontsize="28" x="688" y="528" name="I0(3:0)" orien="R270" />
        <iomarker fontsize="28" x="848" y="528" name="l1(3:0)" orien="R270" />
        <iomarker fontsize="28" x="1024" y="528" name="l2(3:0)" orien="R270" />
        <iomarker fontsize="28" x="1200" y="528" name="l3(3:0)" orien="R270" />
        <instance x="2000" y="2688" name="XLXI_6" orien="R0" />
        <iomarker fontsize="28" x="1232" y="256" name="S(1:0)" orien="R180" />
        <branch name="S(1:0)">
            <wire x2="1296" y1="256" y2="256" x1="1232" />
            <wire x2="1312" y1="256" y2="256" x1="1296" />
            <wire x2="1408" y1="256" y2="256" x1="1312" />
            <wire x2="1424" y1="256" y2="256" x1="1408" />
            <wire x2="1584" y1="256" y2="256" x1="1424" />
            <wire x2="1744" y1="256" y2="256" x1="1584" />
        </branch>
        <instance x="1584" y="2384" name="XLXI_4" orien="R0" />
        <branch name="XLXN_52">
            <wire x2="1264" y1="2688" y2="2704" x1="1264" />
            <wire x2="2064" y1="2704" y2="2704" x1="1264" />
            <wire x2="1472" y1="2688" y2="2688" x1="1264" />
            <wire x2="1504" y1="2688" y2="2688" x1="1472" />
            <wire x2="1536" y1="2688" y2="2688" x1="1504" />
            <wire x2="1584" y1="2688" y2="2688" x1="1536" />
            <wire x2="1584" y1="1904" y2="1904" x1="1472" />
            <wire x2="1472" y1="1904" y2="2688" x1="1472" />
            <wire x2="1584" y1="1472" y2="1472" x1="1504" />
            <wire x2="1504" y1="1472" y2="2688" x1="1504" />
            <wire x2="1584" y1="976" y2="976" x1="1536" />
            <wire x2="1536" y1="976" y2="2688" x1="1536" />
            <wire x2="1584" y1="2352" y2="2688" x1="1584" />
            <wire x2="2064" y1="2688" y2="2704" x1="2064" />
        </branch>
        <bustap x2="784" y1="592" y2="592" x1="688" />
        <branch name="I0(3)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1184" y="592" type="branch" />
            <wire x2="1184" y1="592" y2="592" x1="784" />
            <wire x2="1584" y1="592" y2="592" x1="1184" />
        </branch>
        <bustap x2="784" y1="1088" y2="1088" x1="688" />
        <branch name="I0(2)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1184" y="1088" type="branch" />
            <wire x2="1184" y1="1088" y2="1088" x1="784" />
            <wire x2="1584" y1="1088" y2="1088" x1="1184" />
        </branch>
        <bustap x2="784" y1="1520" y2="1520" x1="688" />
        <branch name="I0(1)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1184" y="1520" type="branch" />
            <wire x2="1184" y1="1520" y2="1520" x1="784" />
            <wire x2="1584" y1="1520" y2="1520" x1="1184" />
        </branch>
        <bustap x2="784" y1="1968" y2="1968" x1="688" />
        <branch name="I0(0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1184" y="1968" type="branch" />
            <wire x2="1184" y1="1968" y2="1968" x1="784" />
            <wire x2="1584" y1="1968" y2="1968" x1="1184" />
        </branch>
        <bustap x2="944" y1="656" y2="656" x1="848" />
        <branch name="l1(3)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1264" y="656" type="branch" />
            <wire x2="1264" y1="656" y2="656" x1="944" />
            <wire x2="1584" y1="656" y2="656" x1="1264" />
        </branch>
        <bustap x2="944" y1="1152" y2="1152" x1="848" />
        <branch name="l1(2)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1264" y="1152" type="branch" />
            <wire x2="1264" y1="1152" y2="1152" x1="944" />
            <wire x2="1584" y1="1152" y2="1152" x1="1264" />
        </branch>
        <bustap x2="944" y1="1584" y2="1584" x1="848" />
        <branch name="l1(1)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1264" y="1584" type="branch" />
            <wire x2="1264" y1="1584" y2="1584" x1="944" />
            <wire x2="1584" y1="1584" y2="1584" x1="1264" />
        </branch>
        <bustap x2="944" y1="2032" y2="2032" x1="848" />
        <branch name="l1(0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1264" y="2032" type="branch" />
            <wire x2="1264" y1="2032" y2="2032" x1="944" />
            <wire x2="1584" y1="2032" y2="2032" x1="1264" />
        </branch>
        <bustap x2="1120" y1="720" y2="720" x1="1024" />
        <branch name="l2(3)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1352" y="720" type="branch" />
            <wire x2="1352" y1="720" y2="720" x1="1120" />
            <wire x2="1584" y1="720" y2="720" x1="1352" />
        </branch>
        <bustap x2="1120" y1="1216" y2="1216" x1="1024" />
        <branch name="l2(2)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1352" y="1216" type="branch" />
            <wire x2="1352" y1="1216" y2="1216" x1="1120" />
            <wire x2="1584" y1="1216" y2="1216" x1="1352" />
        </branch>
        <bustap x2="1120" y1="1648" y2="1648" x1="1024" />
        <branch name="l2(1)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1352" y="1648" type="branch" />
            <wire x2="1352" y1="1648" y2="1648" x1="1120" />
            <wire x2="1584" y1="1648" y2="1648" x1="1352" />
        </branch>
        <bustap x2="1120" y1="2096" y2="2096" x1="1024" />
        <branch name="l2(0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1352" y="2096" type="branch" />
            <wire x2="1352" y1="2096" y2="2096" x1="1120" />
            <wire x2="1584" y1="2096" y2="2096" x1="1352" />
        </branch>
        <bustap x2="1296" y1="784" y2="784" x1="1200" />
        <branch name="l3(3)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1440" y="784" type="branch" />
            <wire x2="1440" y1="784" y2="784" x1="1296" />
            <wire x2="1584" y1="784" y2="784" x1="1440" />
        </branch>
        <bustap x2="1296" y1="1280" y2="1280" x1="1200" />
        <branch name="l3(2)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1440" y="1280" type="branch" />
            <wire x2="1440" y1="1280" y2="1280" x1="1296" />
            <wire x2="1584" y1="1280" y2="1280" x1="1440" />
        </branch>
        <bustap x2="1296" y1="1712" y2="1712" x1="1200" />
        <branch name="l3(1)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1440" y="1712" type="branch" />
            <wire x2="1440" y1="1712" y2="1712" x1="1296" />
            <wire x2="1584" y1="1712" y2="1712" x1="1440" />
        </branch>
        <bustap x2="1296" y1="2160" y2="2160" x1="1200" />
        <branch name="l3(0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1440" y="2160" type="branch" />
            <wire x2="1440" y1="2160" y2="2160" x1="1296" />
            <wire x2="1584" y1="2160" y2="2160" x1="1440" />
        </branch>
        <bustap x2="1312" y1="256" y2="352" x1="1312" />
        <branch name="S(1)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="1312" y="1424" type="branch" />
            <wire x2="1312" y1="352" y2="912" x1="1312" />
            <wire x2="1312" y1="912" y2="1408" x1="1312" />
            <wire x2="1312" y1="1408" y2="1424" x1="1312" />
            <wire x2="1312" y1="1424" y2="1840" x1="1312" />
            <wire x2="1312" y1="1840" y2="2288" x1="1312" />
            <wire x2="1584" y1="2288" y2="2288" x1="1312" />
            <wire x2="1584" y1="1840" y2="1840" x1="1312" />
            <wire x2="1584" y1="1408" y2="1408" x1="1312" />
            <wire x2="1584" y1="912" y2="912" x1="1312" />
        </branch>
        <bustap x2="1408" y1="256" y2="352" x1="1408" />
        <branch name="S(0)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="1408" y="1448" type="branch" />
            <wire x2="1408" y1="352" y2="848" x1="1408" />
            <wire x2="1584" y1="848" y2="848" x1="1408" />
            <wire x2="1408" y1="848" y2="1344" x1="1408" />
            <wire x2="1408" y1="1344" y2="1448" x1="1408" />
            <wire x2="1408" y1="1448" y2="1776" x1="1408" />
            <wire x2="1584" y1="1776" y2="1776" x1="1408" />
            <wire x2="1408" y1="1776" y2="2224" x1="1408" />
            <wire x2="1584" y1="2224" y2="2224" x1="1408" />
            <wire x2="1584" y1="1344" y2="1344" x1="1408" />
        </branch>
        <bustap x2="2560" y1="688" y2="688" x1="2656" />
        <branch name="O(3)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="2232" y="688" type="branch" />
            <wire x2="2232" y1="688" y2="688" x1="1904" />
            <wire x2="2560" y1="688" y2="688" x1="2232" />
        </branch>
        <bustap x2="2560" y1="1184" y2="1184" x1="2656" />
        <branch name="O(2)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="2232" y="1184" type="branch" />
            <wire x2="2232" y1="1184" y2="1184" x1="1904" />
            <wire x2="2560" y1="1184" y2="1184" x1="2232" />
        </branch>
        <bustap x2="2560" y1="1616" y2="1616" x1="2656" />
        <branch name="O(1)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="2232" y="1616" type="branch" />
            <wire x2="2232" y1="1616" y2="1616" x1="1904" />
            <wire x2="2560" y1="1616" y2="1616" x1="2232" />
        </branch>
        <bustap x2="2560" y1="2064" y2="2064" x1="2656" />
        <branch name="O(0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="2232" y="2064" type="branch" />
            <wire x2="2232" y1="2064" y2="2064" x1="1904" />
            <wire x2="2560" y1="2064" y2="2064" x1="2232" />
        </branch>
        <iomarker fontsize="28" x="2656" y="2496" name="O(3:0)" orien="R90" />
    </sheet>
</drawing>