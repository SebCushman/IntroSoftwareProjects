# IntroSoftwareProjects

To make sure this runs, you're going to have to change your working directory. In Visual Studio, right click on the IntroSoftwareProjects project and open the properties. At the
top, in general, select Debugging. The working directory will probably start as "$(ProjectDir)", which is what needs to change. Change it to "$(SolutionDir)Build". Once you've 
done this, it should be able to find all the lib files and DLLs.
