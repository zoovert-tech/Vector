<div align="center">
   <h3>Expandable Vector</h3>
</div>

Own implementation of a vector class with a visualizer

---

<div align="center">
  <h3>Visualizer</h3>
</div>

By default visual studio does not support rendering third-party arrays (just like a vector).

Without Natvis:
<br><img src="img/withoutNatvis.png"></img></br>

With Natvis:
<br><img src="img/withNatvis.png"></img></br>

---
<div align="center">
  <h3>WARNING</h3>
</div>

For the visualizer to work for the vector class, you need to move the file 'Vector_.natvis' to 
<br>'(Drive where VS is installed):\#UserName#\Documents\Visual Studio {Visual Studio version (in my case 2022)}\Visualizers'</br>
in this folder leave this file, then run the project and in debugging it will work.
<br>Example path: 'C:\Users\Sergey\Documents\Visual Studio 2022\Visualizers\Vector_.natvis'</br>
