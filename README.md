<h2>HZSOverlay - 大灾变叠加层插件</h2>

<p><strong>HZSOverlay</strong> 是 <strong>CS:S 大灾变（ZombieScenario）</strong> 模式的一个可选扩展插件，用于显示 <strong>击中提示、连杀提示、胜败提示等屏幕叠加层</strong>。</p>

<p>通过配置文件可自定义每阶段击杀提示材质、叠加显示逻辑与显示条件。</p>

<h3>📦 插件依赖</h3>

<ul>
  <li>编译时必须包含 ZombieScenario API：</li>
</ul>

<pre><code>#include &lt;HanZombieScenarioAPI&gt;
</code></pre>

<ul>
  <li>依赖文件：HanZombieScenarioAPI.inc</li>
  <li><strong>必须配合 ZombieScenario 主插件使用</strong></li>
</ul>

<h3>⚙️ 配置项说明</h3>

<ul>
  <li><strong>enable_plugins</strong><br> 是否启用此插件。<br> <strong>默认值：1</strong></li>

  <li><strong>Enable_Hitmarker</strong><br> 是否启用击中提示（Hitmarker）。<br> <strong>默认值：0</strong></li>

  <li><strong>Hitmarker_Path</strong><br> 击中提示材质路径。<br> 示例：<code>overlays/hitmarker/hitmarker</code></li>

  <li><strong>Enable_KillOverlay</strong><br> 是否启用击杀连杀提示。<br> <strong>默认值：1</strong></li>

  <li><strong>Kill_Combo_Wait</strong><br> 连杀等待时间（秒）。在此时间内连续击杀将触发连杀叠加。<br> <strong>默认值：10.0</strong></li>

  <li><strong>Combo0_KillCount</strong><br> 连杀第1阶段：击杀数小于该值时播放第1阶段提示。<br> <strong>默认值：10</strong></li>
  <li><strong>ShowKill_Combo0_Path</strong><br> 第1阶段提示材质路径。</li>

  <li><strong>Combo1_KillCount ～ Combo5_KillCount</strong><br> 分别为第2～第6阶段连杀判定击杀数阈值。每阶段之间按击杀数递增。</li>
  <li><strong>ShowKill_ComboX_Path</strong><br> 每阶段对应的提示贴图路径（X = 1~5）。</li>

  <li><strong>Max_Combo_KillCount</strong><br> 连杀阶段最大上限。超出后循环播放第6阶段提示。<br> <strong>默认值：70</strong></li>

  <li><strong>Enable_RoundWin_Overlay</strong><br> 是否启用胜利提示叠加层。<br> <strong>默认值：1</strong></li>
  <li><strong>RoundWin_Overlay_Path</strong><br> 胜利提示材质路径。</li>

  <li><strong>Enable_RoundLost_Overlay</strong><br> 是否启用失败提示叠加层。<br> <strong>默认值：1</strong></li>
  <li><strong>RoundLost_Overlay_Path</strong><br> 失败提示材质路径。</li>
</ul>

<h3>⚠️ 注意事项</h3>
<ul>
  <li>由于 CS:S 引擎限制，同时只能显示一个叠加层。</li>
  <li>如果开启了多个叠加层（例如：Hitmarker 与 KillOverlay），可能会出现闪烁或冲突。</li>
  <li><strong>建议选择性启用其中一个，如无法接受闪烁效果。</strong></li>
</ul>

<hr>

<h2>HZSOverlay - ZombieScenario Overlay Plugin</h2>

<p><strong>HZSOverlay</strong> is an optional extension plugin for <strong>CS:S ZombieScenario</strong> mode. It adds customizable <strong>screen overlays for hit markers, killstreaks, and round results</strong>.</p>

<p>Each overlay stage and texture can be fully configured in the plugin’s config file.</p>

<h3>📦 Requirements</h3>

<ul>
  <li>You must include the ZombieScenario API:</li>
</ul>

<pre><code>#include &lt;HanZombieScenarioAPI&gt;
</code></pre>

<ul>
  <li>Required file: HanZombieScenarioAPI.inc</li>
  <li><strong>Must be used together with the main ZombieScenario plugin</strong></li>
</ul>

<h3>⚙️ Configuration Variables</h3>

<ul>
  <li><strong>enable_plugins</strong><br> Enable or disable this plugin.<br> <strong>Default: 1</strong></li>

  <li><strong>Enable_Hitmarker</strong><br> Enable hit marker overlay on damage.<br> <strong>Default: 0</strong></li>

  <li><strong>Hitmarker_Path</strong><br> Path to hit marker overlay texture.<br> Example: <code>overlays/hitmarker/hitmarker</code></li>

  <li><strong>Enable_KillOverlay</strong><br> Enable killstreak overlay.<br> <strong>Default: 1</strong></li>

  <li><strong>Kill_Combo_Wait</strong><br> Killstreak combo timeout (seconds).<br> <strong>Default: 10.0</strong></li>

  <li><strong>Combo0_KillCount</strong><br> Stage 1 combo: shown when kills &lt; value.<br> <strong>Default: 10</strong></li>
  <li><strong>ShowKill_Combo0_Path</strong><br> Overlay texture path for stage 1.</li>

  <li><strong>Combo1_KillCount ~ Combo5_KillCount</strong><br> Threshold values for combo stages 2–6.</li>
  <li><strong>ShowKill_ComboX_Path</strong><br> Overlay texture path for each stage (X = 1~5).</li>

  <li><strong>Max_Combo_KillCount</strong><br> Max combo count. Loops stage 6 if exceeded.<br> <strong>Default: 70</strong></li>

  <li><strong>Enable_RoundWin_Overlay</strong><br> Enable round win overlay.<br> <strong>Default: 1</strong></li>
  <li><strong>RoundWin_Overlay_Path</strong><br> Texture path for round win overlay.</li>

  <li><strong>Enable_RoundLost_Overlay</strong><br> Enable round lost overlay.<br> <strong>Default: 1</strong></li>
  <li><strong>RoundLost_Overlay_Path</strong><br> Texture path for round lost overlay.</li>
</ul>

<h3>⚠️ Notes</h3>
<ul>
  <li>Due to engine limitations, only one overlay can be displayed at a time.</li>
  <li>Enabling multiple overlays (e.g., hit marker + kill overlay) may cause flickering.</li>
  <li><strong>If flickering is an issue, consider disabling one of the overlays.</strong></li>
</ul>
