//Tom Kannenberg 2023, C++17

#include "TKCursor/TKCursor.h"
#include "TKMenu/TKMenu.h"
using namespace TKMenu;
using namespace TKCursor;


int main() {
    AllowSetForegroundWindow(GetCurrentProcessId());

    MenuBuilder builder = MenuBuilder();

    //Grades Page
    CursorInfo gradesInfo({ 4, 5 },
        { "German", "Mathematics", "Social Science" ,"Music", "Art",
          "3",      "2",           "3",              "2",     "2",
         "Physical Education" ,"English SL", "Natural Science", "Work,Eco & Tech", "Ethics",
         "2",                   "1",          "2",               "3",                "2" }, true, true, 1);
    builder.addCursor("grades", "traditional", gradesInfo);

    //Traditional Education Page
    CursorInfo eduInfo({ 1, 1 }, { "Erw. Sekundarabschluss I - 2021 *" }, { true }, { "grades" }, true, 2);
    builder.addCursor("traditional", "education", eduInfo);

    //C++ Intro Page
    CursorInfo cintroInfo({ 1, 4 }, {
        "My first introduction into C++ was in 2021 when i was getting bored of C#.",
        "I learned the C++ Syntax through SoloLearn in about 3 weeks, while it was still",
        "free. I didn't really know what to do with it, so i just left it there for a while",
        "and then started to learn how to properly use C++ and Programming in 2022."
        }, false, true, 1);
    builder.addCursor("c++intro", "c++", cintroInfo);

    //C++ Learning Page
    CursorInfo clearnInfo({ 1, 5 }, {
        "With the C++ Syntax already learned, I started to learn how to properly use C++,",
        "it was 2022 and I planned how I could learn C++ practically with something fun.",
        "At first, I made some programs to calculate game related values using only the basics.",
        "After that, I made some simpler games like Chess & Snake, but spiced it up,",
        "by using extensive amounts of OOP & Pointers."
        }, false, true, 1);
    builder.addCursor("c++learn", "c++", clearnInfo);

    //C++ Ambitions Page
    CursorInfo cambInfo({ 1, 8 }, {
        "At first my Idea of C++ was that it's the most difficult language to learn, which I found",
        "to be not true, it's just a bit more complex than C# or Java, but it's not that hard to learn.",
        "I often explain my code to my friends, and they understand it, even though they don't code.",
        "My ambitions with C++ are to be a highly efficient programmer, even as beginner I thought,",
        "if my code is bad, it's gonna run the bad code faster than the same bad code in C# or Java,",
        "so I learned how to become a better programmer, and I'm still learning, I'm not perfect,",
        "but my efficiency is never capped by the language, but by my own knowledge, and that's",
        "what I love about C++."
        }, false, true, 1);
    builder.addCursor("c++amb", "c++", cambInfo);


    //C++ Page
    CursorInfo cppInfo({ 1, 3 }, { "Introduction to C++ *", "How i learned C++ *", "C++ Ambitions *" }, { true, true, true }, { "c++intro", "c++learn", "c++amb" }, true, 4);
    builder.addCursor("c++", "exp", cppInfo);

    //Java Intro Page
    CursorInfo javaintroInfo({ 1, 7 }, {
        "My first introduction into Java was in 2010 when I was seven years old.",
        "I had a Java book my father gave me, and I started to make some simple",
        "programs, like a calculator or a program that creates some clickable buttons.",
        "My father didn't really like Java himself, so he didn't really help me with it.",
        "I then had a full break from Java until 2022, when I started to learn it again.",
        "Prior to learning Java itself in 2022, I learned how to program Spigot Plugins,",
        "doing that without Java, I used a program called Visual Bukkit."
        }, false, true, 1);
    builder.addCursor("javaintro", "java", javaintroInfo);

    //Java Learning Page
    CursorInfo javalearnInfo({ 1, 7 }, {
        "I didn't really need to learn Java itself, because I already knew C++, but I still",
        "needed to learn specifics, maven and how certain things like threads work in Java.",
        "Before I learned Java, I learned how to program Spigot Plugins, which is a Java",
        "based API for Minecraft, Visual Bukkit was a program that allowed me to program",
        "without knowing Java, I began using it as a Hobby back in 2019, and I got a taste of",
        "how functions work, and how to use them, I then started to learn Java in 2022,",
        "which was essentially like learning a library, because I already knew C++."
        }, false, true, 1);
    builder.addCursor("javalearn", "java", javalearnInfo);

    //Java Page
    CursorInfo javaInfo({ 1, 2 }, { "Introduction to Java *", "How i learned Java *" }, { true, true }, { "javaintro", "javalearn" }, true, 3);
    builder.addCursor("java", "exp", javaInfo);

    //C# Intro Page
    CursorInfo csharpintroInfo({ 1, 7 }, {
        "Early in life, I was fascinated by the idea of crafting my own video games",
        "and bringing my imagination to life through interactive experiences.",
        "Once i was sixteen in 2019 I was looking into game engines to pursuit this idea.",
        "Unreal Engine sounded cool, but very complicated, so I went with Unity,",
        "and I had to make some simple scripts to even get started, so I looked into C#.",
        "As already mentioned, I was getting bored of C# so I started, not all to deep into C#,",
        "to learn C++ with the same mentality of wanting the hard way."
        }, false, true, 1);
    builder.addCursor("csharpintro", "csharp", csharpintroInfo);

    //C# Learning Page
    CursorInfo csharplearnInfo({ 1, 7 }, {
        "When I started to look into C# scripts for Unity, I was not really familiar with the syntax,",
        "I watched a lot of tutorials, and I learned how to make some simple scripts,",
        "but only by memorizing the \"commands\" and not really understanding what they do,",
        "similiar to traditional education, I was just memorizing the answers, and not really",
        "understanding the logic behind it, I later used C# after I learned C++ to make some simple",
        "Unity examples, but I didn't really like it, because it wasn't as challeging, and I wasn't really",
        "into Game Development anymore. I use it for Unity Mods sometimes though."
        }, false, true, 1);
    builder.addCursor("csharplearn", "csharp", csharplearnInfo);

    //C# Page
    CursorInfo csharpInfo({ 1, 2 }, { "Introduction to C# *", "How i learned C# *" }, { true, true }, { "csharpintro", "csharplearn" }, true, 3);
    builder.addCursor("csharp", "exp", csharpInfo);

    //Experience Page
    CursorInfo expInfo({ 1, 3 }, { "C++ *", "Java *", "C# *" }, { true, true, true }, { "c++", "java", "csharp" }, true, 4);
    builder.addCursor("exp", "education", expInfo);

    //Technical Skills Page
    CursorInfo techskillsInfo({ 1, 10 }, {
        "Experience with Linux",
        "Experience with Windows",
        "Proficient in C++",
        "Proficient in Java",
        "Experience with C#",
        "Basic Experience with Web Development",
        "Familiar with MySQL",
        "Basic Experience with Graphics libraries",
        "Experience with Hardware, Computers & Servers",
        "Experience with Neural Networks in C++"
        }, true, true, 1);
    builder.addCursor("techskills", "skills", techskillsInfo);

    //Languages Page
    CursorInfo languagesInfo({ 1, 2 }, {
        "English (Everyday-Language)",
        "German (Native)"
        }, true, true, 1);
    builder.addCursor("languages", "skills", languagesInfo);

    //Software Page
    CursorInfo softwareInfo({ 1, 6 }, {
        "Visual Studio",
        "Rider",
        "IntelliJ IDEA",
        "Git Basics",
        "VMware Basics",
        "Blender Basics"
        }, true, true, 1);
    builder.addCursor("software", "skills", softwareInfo);

    //Operating Systems Page
    CursorInfo osInfo({ 1, 3 }, {
        "Windows (10 & 11)",
        "Linux",
        "Android"
        }, true, true, 1);
    builder.addCursor("os", "skills", osInfo);

    //Skills Page
    CursorInfo skillsInfo({ 1, 4 }, { "Technical Skills *", "Languages *", "Software *", "Operating Systems *" }, { true, true, true, true }, { "techskills", "languages", "software", "os" }, true, 5);
    builder.addCursor("skills", "education", skillsInfo);

    //Education Page
    CursorInfo educationInfo({ 1, 4 }, { "Traditional Education *", "Experience *", "Skills *", "SoloLearn *" }, { true, true, true, false }, { "traditional", "exp", "skills", "" }, true, 5);
    builder.addCursor("education", "main", educationInfo);

    //Tom History Page
    CursorInfo tomInfo({ 1, 9 }, {
        "Tom Kannenberg",
        "",
        "Born 23rd of March 2023",
        "Age 20 Years",
        "C++ Experience > 3 Years",
        "Java Experience > 3 Years",
        "General Tinkering Knowledge > 13 Years",
        "SoloLearn C++ Certificate 2021",
        "2.2 Average Grades, 80%"
        }, false, true, 1);
    builder.addCursor("tom", "main", tomInfo);


    //Main Page
    CursorInfo mainInfo({ 1, 2 }, { "Tom Kannenberg *", "Education *" }, { false, true }, { "tom", "education" });
    builder.initialize(mainInfo);

    return 0;
}
