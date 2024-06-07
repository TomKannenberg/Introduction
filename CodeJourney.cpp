//Tom Kannenberg 2023, C++17

#include "TKCursor/TKCursor.h"
#include "TKMenu/TKMenu.h"
using namespace TKMenu;
using namespace TKCursor;


int main() {
    AllowSetForegroundWindow(GetCurrentProcessId());

    MenuBuilder builder = MenuBuilder();

    //Technical Skills Page
    CursorInfo techskillsInfo({ 1, 10 }, {
        "Broad Set of Programming Skills",
        "Proficient in C++",
        "Proficient in Java",
        "Proficient C#",
        "Proficient in Scripting Languages",
        "Familiar with SQL",
        "Experience with Hardware, Computers & Servers",
        "Basic Experience with Graphics libraries",
        "Experience with Windows",
        "Experience with Linux"
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
        "Vcpkg",
        "Git",
        "IntelliJ",
        "ChatGPT / LLM's",
        "VMware"
        }, true, true, 1);
    builder.addCursor("software", "skills", softwareInfo);

    //Operating Systems Page
    CursorInfo osInfo({ 1, 4 }, {
        "Windows",
        "Linux",
        "Android",
        "Ios"
        }, true, true, 1);
    builder.addCursor("os", "skills", osInfo);

    //Skills Page
    CursorInfo skillsInfo({ 1, 4 }, { "Code *", "Language *", "Software *", "OS *" }, { true, true, true, true }, { "techskills", "languages", "software", "os" }, true, 5);
    builder.addCursor("skills", "main", skillsInfo);

    //Code Jr.
    CursorInfo jrInfo({ 1, 10 }, {
        "2010,",
        "",
        "I got my first laptop on my 7th or 8th birthday,",
        "at first I was only exploring the internet",
        "and games. When I got a Java Book this changed.",
        "My father bought me a Java book for Kids, it",
        "was overwhelming and I mostly typed word by word",
        "until I lost interest. Around the same time, I got",
        "into PS3 Minecraft Edition modding using the Laptop",
        "and tools found in the internet."
        }, false, true, 1);
    builder.addCursor("jr", "adventure", jrInfo);

    //High School
    CursorInfo highInfo({ 1, 12 }, {
        "2016,",
        "",
        "During 7th grade I had the desire to learn,",
        "from the years before I already had a lot of experience",
        "with setting up Game Servers with mods and public hosting.",
        "The idea of making my own Server mods was very intruiging",
        "so I tried to learn Java in 7th grade, then in 8th grade",
        "and one more failed attempt in 9th grade, until I finally",
        "overcame the boredom of the use of programming syntax",
        "and environments in 10th grade, having lead to making mods Daily.",
        "Turned out, I already had the problem solving skills from",
        "trying to break my Schools assignments to find my own solutions instead!"
        }, false, true, 1);
    builder.addCursor("high", "adventure", highInfo);

    //C++
    CursorInfo cppInfo({ 1, 12 }, {
        "2020,",
        "",
        "I wanted to learn everything, not being limited by Java.",
        "Curious of how the magic worked behind most programs,",
        "C++ came along and I figured it will explain all the magic.",
        "The idea I had learning C++ is that I don't care how long I",
        "will have to learn, at somepoint I will understand, and now",
        "where I do, it's dissappointingly easy and less magical than",
        "I thought... I always thought there are millions of different",
        "Syntax Rules one has to follow, I saw 10 books for just one",
        "Language in my fathers Office, turns out the millions I was",
        "trying to conquer turned out to be less then a hundred..."
        }, false, true, 1);
    builder.addCursor("cpp", "adventure", cppInfo);

    //Pointers
    CursorInfo ptrInfo({ 1, 12 }, {
        "2021,",
        "",
        "When trying to read code, sometimes even use code or write code",
        "I regularly came across pointers, at first randomly putting the",
        "ptr* or ref& symbols, before or after variables got me through",
        "without a problem. Still, I was becoming more and more frustrated",
        "that it slowed me down using them, so I made 2 programs to train.",
        "At first I thought making a Chess game would be nice, it also would",
        "help me deepen my understanding of classes and inheritance, although",
        "the inheritance was a bit overrated, I quickly got to understand",
        "Pointers, it took a bit longer for references as I haven't learned",
        "about memory yet, which looking back, would have been a bit less challenging."
        }, false, true, 1);
    builder.addCursor("ptr", "adventure", ptrInfo);

    //Dev
    CursorInfo devInfo({ 1, 12 }, {
        "2022,",
        "",
        "After getting proficient in C++ I took the oppurtunity, Freelancing",
        "not only could I get paid but also I was getting known with developing",
        "in groups. So I worked on smaller Java projects as lead developer and",
        "later in 2022 I would work on a Official Game Servers information retriever",
        "where I would get my first experience with version control and working",
        "under leadership in a bit bigger then before project and in C++.",
        "I also made use of my programming skills to make tools that help my",
        "everyday life, for example I was playing games in a community and made",
        "tools to maximize efficiency of things like blueprint crafting and",
        "mutation breeding. To further develop my skills I also taught a lot of People!"
        }, false, true, 1);
    builder.addCursor("dev", "adventure", devInfo);

    //Prep
    CursorInfo prepInfo({ 1, 12 }, {
        "2023,",
        "",
        "Following a successful year full of challenges and new found friends,",
        "I took a break from what I did to focus on pushing my knowledge",
        "to a broader perspective, I went into 2D & 3D Graphics, Maths, Games",
        "then in and out of Game Modding / Hacking, Reverse Engineering, Client & Server",
        "Programming, Scripting, File Formats & Reverse Engineering, En&Decryption",
        "and lot more smaller skills make myself adaptable to any environment.",
        "I started making bigger projects on my own whilest working with others",
        "as Co-Lead, getting friends to work with me on my Own Projects",
        "Ultimately documenting more and more of my work to build a Resume.",
        "2023 was no doubt my craziest year so far, turning into someone who can code Anything."
        }, false, true, 1);
    builder.addCursor("prep", "adventure", prepInfo);

    //2024
    CursorInfo t24Info({ 1, 10 }, {
        "2024,",
        "",
        "An Unwritten Chapter, yet I've already prepared myself with goals!",
        "With the experience I've gotten over the years I feel qualified enough",
        "to finally apply for a real job, getting resources and investing them wisely",
        "to grow capable of changing the world with more resource demanding projects",
        "and of course growing my skills and mindset. 2024 has to become the year I've",
        "dedicated my programming studies towards. I will always keep learning so I have to",
        "move on and expose myself to more tasks and embrace stress to expand my mental",
        "and physical capacitiy",
        }, false, true, 1);
    builder.addCursor("2024", "adventure", t24Info);

    //Adventure
    CursorInfo adventureInfo({ 1, 7 }, { "Code Jr. *", "Highschool *", "More useful of a Language *", "Understanding Pointers *", "Development *", "Preparations *", "2024 *"}, {true, true, true, true, true, true, true}, {"jr", "high", "cpp", "ptr", "dev", "prep", "2024"}, true, 8);
    builder.addCursor("adventure", "main", adventureInfo);

    //Journey
    CursorInfo journeyInfo({ 1, 9 }, {
        "This Program,",
        "",
        "Originally this program was a fun project to test how far I can push pointers,",
        "I tried to push as much pointer madness into this project as possible.",
        "It was like a puzzle making it, I fully understood pointers already but",
        "this made me read and write pointers subconscious aswell as crafting",
        "my oop style.",
        "",
        "Now being 2024 I use it to showcase my skills and experiences.",
        }, false, true, 1);
    builder.addCursor("journey", "creative", journeyInfo);

    //ZomWy
    CursorInfo zwInfo({ 1, 12 }, {
        "ZomWy : Zombie Wyvern,",
        "",
        "For the Game Ark Survival Ascended me and a buddy came together and",
        "made a seamless connection between Discord, a Client and the Game.",
        "ZomWy essentially is a Bot that is not fully automate but rather in",
        "Control of the other players in your tribe, so you may go asleep and",
        "still be useful to your tribemates, you set a Discord Channel, they say",
        "Farm Stone, Farm Metal and the bot starts hitting Rocks and filters items",
        "to be dropped depending on what we are farming rn, efficiently farming the",
        "most materials possible using only one instead of 2 players.",
        "The ZomWy Server application communicates through ZMQ to the Client and",
        "through DPP to Discord, also has selfmade anti proxy and ddos protection."
        }, false, true, 1);
    builder.addCursor("zw", "creative", zwInfo);

    //XPAC Tool
    CursorInfo xpacInfo({ 1, 12 }, {
        "Sonic and Sega All-Star Racing,",
        "",
        "When I first got into game modding I found out that one of",
        "my Childhood Games had no Mods but a small Community, I used the",
        "opportunity to make this modding tool to unpack and repack Game Files",
        "I also added functionality so that it automatically unpacks and repacks",
        "texture files from the sub archives inside of the .xpac.",
        "The XPAC Tool gave me a lot of insight into encryption, decryption and",
        "Threaded Optimizations. I started on my laptop on a 3 hour car ride after",
        "which I could successfully extract all textures from the archive containing",
        "encrypted subarchives in less than 30seconds, a few days later I got to work",
        "on optimizing it bringing it down to .11 seconds on my PC and .45 seconds on my Laptop!"
        }, false, true, 1);
    builder.addCursor("xpac", "creative", xpacInfo);

    //GetDown
    CursorInfo gdInfo({ 1, 12 }, {
        "GetDown,",
        "",
        "During my time in High School and just my All Time Favorite",
        "Minecraft Gamemode GetDown where you start at the top and must",
        "carefully Get Down using Jump & Run and RNG mechanics, getting coins",
        "on the way down given coin blocks and double coin blocks aswell as",
        "Lucky Blocks, which gave a random effect, the Original Network that",
        "hosted the Gamemode, Rewinside.tv, was shut down, along many remakes",
        "I made again and again, this one is the best so far, updated to work",
        "Perfectly with the new Minecraft versionsm. The messages are a bit",
        "inappropriate as the game was made for my friends and myself to fool",
        "around and have some fun in a few Splitscreen Controller sessions."
        }, false, true, 1);
    builder.addCursor("gd", "creative", gdInfo);

    //ImGui Template
    CursorInfo imguiInfo({ 1, 12 }, {
        "GC's ImGui Template,",
        "",
        "When I first got into designing Gui's I instantly thought of ImGui as",
        "I header a lot of great things about in on Youtube and gave it a shot.",
        "My First Objective was to get a Standalone Window working, which meant",
        "I had to make my own window movement, for that I checked if the cursor is",
        "in the window headers bounding box and kept track of when and where we clicked.",
        "This made the window feel perfect for my style, even better than windows default.",
        "The Second feature I opted for was a blurred background, fortunately there is an",
        "older feature that I was able to use from the windows libraries that made the blur",
        "possible without the use of any additional shaders, a challenge wwas were it did not",
        "like window rounding, the blur was rectangular, fortunately I found a way to force it."
        }, false, true, 1);
    builder.addCursor("imgui", "creative", imguiInfo);

    //SkylanderEmulator
    CursorInfo skylanderInfo({ 1, 14 }, {
        "SkylanderEmulator,",
        "",
        "One of my First 2024 Projects was an Android Java & C++ App with",
        "a C++ TDP Receiver as backend, connecting the phone with the backend to",
        "be able to play as your favorite Skylander on either RPCS3 or CEMU. (my custom builds)",
        "At first I went into NFC and looked at how the figures are read by the portal",
        "but after a while I though emulating Single Skylanders would be to Gimmicky",
        "So I thought instead I emulate the Portal and controll all skylanders from",
        "From the phone. I got the Idea whilest playing on RPCS3, which has an awesome",
        "Inbuilt Skylanders Emulator, the problem I see with it is that you need to find",
        "the files of your skylander every time you want to switch and it's less immersive.",
        "My Goal with this project was to make the Skylander games feel more Immersive on PC.",
        "Now where I got almost all Skylanders and Traps in the App, I'm confident that",
        "this is the 2nd most immersive way to play Skylanders. (not trying to compete with the toys)"
        }, false, true, 1);
    builder.addCursor("skylander", "creative", skylanderInfo);

    //Zif
    CursorInfo zifInfo({ 1, 10 }, {
        "Zif Pattern,",
        "",
        "This Script is in ImHex's Pattern Language, which I do really like!",
        "Making Structs and functions in a C / Rust style manner is really fun and",
        "the visualization makes things a lot easier when reverse engineering a",
        "file format! The Zif format is one of the formats extracted out of my",
        "XPAC Tool, it holds Logic of the counterpart .zig which in turn holds",
        "Data like textures and 3D models / Animations. The challenge in this",
        "Project was that due to it's unique and creative syntax I had to learn.",
        "As I progressed, I worked with the Documentation and had lots of fun.",
        }, false, true, 1);
    builder.addCursor("zif", "creative", zifInfo);

    //Creative
    CursorInfo creativeInfo({ 1, 7 }, { "Code Journey *", "ZomWy *", "XPAC Tool *", "GetDown *", "ImGui Template *", "SkylanderEmulator *", ".Zif Pattern *" }, { true, true, true, true, true, true, true }, { "journey", "zw", "xpac", "gd", "imgui", "skylander", "zif" }, true, 8);
    builder.addCursor("creative", "main", creativeInfo);

    //Tom History Page
    CursorInfo tomInfo({ 1, 13 }, {
        "Tom Kannenberg",
        "",
        "Born 23rd of March 2023",
        "Age 21 Years",
        "C++ Experience 3+ Years",
        "Java Experience 3+ Years",
        "General Tinkering Knowledge 14+ Years",
        "SoloLearn C++ Certificate 2021",
        "SoloLearn Advanced C++ Certificate 2024",
        "SoloLearn Advanced C Certificate 2024",
        "SoloLearn Advanced C# Certificate 2024",
        "SoloLearn Advanced Python Certificate 2024",
        "2.2 Average Grades, 84%"
        }, false, true, 1);
    builder.addCursor("tom", "main", tomInfo);


    //Main Page
    CursorInfo mainInfo({ 1, 4 }, { "Stats *", "Adventure Mode *", "Creative Mode *", "Skills *" }, { true, true, true }, { "tom", "adventure", "creative", "skills" });
    builder.initialize(mainInfo);

    return 0;
}
