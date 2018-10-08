# 学会使用construct2制作自己的小游戏

- 依稀记得小时候玩别人制作的游戏，自己每每有不痛快的时候，就在幻想着能自己做一个喜欢的游戏，想怎么玩就怎么玩，那该是多么舒服的一件事情。现在，学习了一定知识，我们终于可以制作自己的小游戏啦，想想就有点小激动呢~

    ![](https://i01piccdn.sogoucdn.com/faaa05f9eea28625)
- 好啦，在激动过后，我们正式开始学习如何使用construct2制作自己的小游戏。

## 准备工作

- 制作工具：construct2 [下载地址](https://i01piccdn.sogoucdn.com/faaa05f9eea28625)

- 模型资源：在网络上寻找自己喜欢的模型，用于游戏的角色，武器，特效的引入。

  (例如大家可以在网络上寻找喜欢的人物图片，进行抠图之后就可以引入游戏并和他愉快的玩耍啦！)

## 正式开始

### 1.游戏的策划

#### 游戏名称：

- The war of freedom

#### 楔子：

- 距离上次星球大战不久，身为宇宙帝国侦查兵的Jackey不愿再被奴隶一样使唤。他也有感情，也有家庭，也有自己渴望的生活。于是他拿起武器，反戈一击，用自己的血肉之躯，抵抗残暴的统治者，发起一场自由之战，找回属于他的自由。

#### 玩法：

- 操控Jackey，用自己精妙绝伦的射击技巧和灵动飘逸的身法，击败这些来讨伐你的黑衣人。战胜他们，找回自由！

#### 人设与道具:

- 侦察兵Jackey:掌握精湛射击技巧的他总是弹无虚发，能够与自己的武器“曙光审判”合二为一，人枪一体，发出震慑敌人的光弹。为了找回属于自己的自由，他别无选择的与黑衣人展开了战斗。

- 黑衣人：为了讨伐背叛帝国的Jackey，他们奉命前来了结他的性命，是Jackey归乡途中最大的绊脚石。

### 2.游戏设计

- 第一步 制作游戏背景图
    - 在construct2中新建一个项目

![](http://a4.qpic.cn/psb?/V1186OFx1RNIby/OaoJ8Kd7oZAGXH52Xhv0iNb7kJIQXtvPYedjzE9hwpQ!/m/dC8BAAAAAAAAnull&bo=1gGbAQAAAAADB28!&rf=photolist&t=5)

    - 鼠标双击空白处后选择Tiled Background创建一个背景

![](http://a4.qpic.cn/psb?/V1186OFx1RNIby/Cc5NH4X3Z3BuTeYVQlpj7MvVMQ5W*pyPHB0tFQ5J68M!/m/dFMBAAAAAAAAnull&bo=WAIGAgAAAAADB3w!&rf=photolist&t=5)
    
    - 可以发现光标现在变成了十字型，我们点击背景，弹出对话框，我们点击打开文件图标，选择已经准备好的背景

![](http://a3.qpic.cn/psb?/V1186OFx1RNIby/ZZo3R4Km3AGvE6Z*Qchn32MaFgEeMBC9QJmhGrZv2Lg!/m/dFYAAAAAAAAAnull&bo=BAKJAQAAAAADB6w!&rf=photolist&t=5)

    - 接下来我们调整背景大小使之适应画布，点击背景图，在左侧属性框内调整size为（1280,1024）

![](http://a2.qpic.cn/psb?/V1186OFx1RNIby/IlL1aNXQ4oToVL8jHVwj8uP6mSEqUsEx.Z*zu9njfRA!/m/dDUBAAAAAAAAnull&bo=*ADLAAAAAAADBxU!&rf=photolist&t=5)
    
    - 完成之后大概就是这样啦

![](http://a2.qpic.cn/psb?/V1186OFx1RNIby/KcoEq9GuohQHF59*QTU5cNpy.RwQwaf5wTD1gxJNbNA!/m/dEkBAAAAAAAAnull&bo=ewcPBAAAAAADB1U!&rf=photolist&t=5)
    
    - 这时，我们点击run图标运行，浏览器将自动打开并展示游戏，你就能看到你的设计的背景图啦~

![](http://a4.qpic.cn/psb?/V1186OFx1RNIby/yF6Etg9.W*8KkNTVnO5Vt9yPH2PR1ngh2HiLfhSZUcw!/m/dDMBAAAAAAAAnull&bo=agFsAAAAAAADByU!&rf=photolist&t=5)

- 第二步 添加游戏对象

    - 首先我们先去把背景对象锁定了，这样才不会被我们再次选中。画布由多个层组成，我们可以在不同的层放置不同的对象，可以通过调整层的上下顺序来调整对象的前后显示，层可以被隐藏或者锁定，平滚特效等。背景放置于最底层，其他对象如玩家，怪物，子弹等放置在上面的几层。点击layer，将背景layer1更名为Background并锁定。

        ![](http://a1.qpic.cn/psb?/V1186OFx1RNIby/75p2vNeCDEMr5DxrAris.*RR*rIld0SDr2mWjkEGYC0!/m/dDQBAAAAAAAAnull&bo=GAHeAQAAAAADB.Q!&rf=photolist&t=5)    
    -  新加入一个层layer2，我们将要在这个层上进行主要的操作，所以把它改名为Main并选中。

        ![](http://a1.qpic.cn/psb?/V1186OFx1RNIby/MfnybTvGqi8eQcDRLYEvbsSJ6wnseY9VI*UI8lgoseE!/m/dFQBAAAAAAAAnull&bo=GAFlAAAAAAADB14!&rf=photolist&t=5)

    - 回到画布中，右键插入一个对象，我们选择Mouse对象，我们需要鼠标输入控制。同样的添加Keyboard对象。

        ![](http://a3.qpic.cn/psb?/V1186OFx1RNIby/hFmIf72d09v8of6ePMl5eHemsYIttoyIUSCKTfFvC28!/m/dFIBAAAAAAAAnull&bo=WAIGAgAAAAADB3w!&rf=photolist&t=5)

    - 添加游戏对象，我们用sprite（精灵）对象来置入，方法跟背景和Mouse对象一样： 
    1、右键插入新对象 
    2、选择Sprite对象 
    3、当鼠标变成十字，在画布中点击 
    4、弹出对话框，点击open 图标，加载准备好的素材
    5、保存并关闭对话框 
    
    - 为了方便辨别，我们可以在他们各自的Properties bar属性面板里将Name属性里更改。依次更改Player,Monster,Bullet,Explosion（玩家，怪物，子弹，爆炸特效）。
    
    - 添加行为，通过寻找网上的资源，我们了解到以下的几种Behavior:
    
    >     8 Direction movement: 这个行为可以让你实现给角色添加方向移动（方向键）的功能。 
    >  
    >     Bullet movement:这个行为让对象朝着它当前的角度移动，比如，本例中玩家射出的子弹的移动行为，不要被这名字迷惑了，它不只适用于子弹，也可以应用于怪物等移动。在Contruct2里所有的移动行为都是通过添加速度向前行进。 
    > 
    >     Scroll to：这个行为可以让运行时画布随着对象移来移去（滚动）。这个行为很适合于角色。 
    > 
    >     Bound to layout：这个行为可以防止对象离开画布区域。这个行为对于角色来说也很重要。 
    > 
    >     Destroy outside layout:当对象离开画布区域时，就将其销毁。比如本例中的子弹，如果不销毁的话，虽然子弹离开画布区域了，但是依然暂用内存。所以我们需要及时销毁不再需要的对象。 
    > 
    >     Fade:这个行为可以给对象添加淡出效果，用于爆炸等特效的消失。

    - 我们给角色player添加8 direction movement行为：选中player，在properties bar属性面板里，找到Behaviors分类，点击Add/Edit弹出Behaviors行为对话框。选择添加8 direction movement。

        ![](http://a3.qpic.cn/psb?/V1186OFx1RNIby/swzhDnd*tklLcAYezk8bex4qYUFTbmajD5P46hwOwhQ!/m/dFIBAAAAAAAAnull&bo=pwGvAQAAAAADByo!&rf=photolist&t=5)

    - 接着以同样的方法给player添加Scroll To和Bound to layout行为，此时”player:Behaviors”对话框如下：

        ![](http://a1.qpic.cn/psb?/V1186OFx1RNIby/TjKC7U1hwhwCptJ4gbHPUdeewvwPsqf9JwhGKcVeTA0!/m/dDQBAAAAAAAAnull&bo=XAEZAQAAAAADB2c!&rf=photolist&t=5)

    - 关闭行为对话框。点击运行查看游戏！此时我们已经可以移动角色，屏幕也跟随角色移动，而且通过设置Bound to layout行为后，角色也不能移出画布区域。
    
    - 添加其他行为，我们以同样的方法给其他对象添加相应的行为如下:

        给Bullet对象添加Bullet movement和Destroy outside layout行为。 
        
        给Monster对象添加Bullet movement行为。 
        
        给Explosion对象添加Fade行为。Fade行为默认会销毁对象，所以不用担心对象有没有销毁。

    - 此时，我们再运行查看游戏，会发现怪物一下子就飞出去了。我们来编辑下怪物的行为，选中Monster怪物对象。看到properties bar属性面板中，我们会发现属性栏里多出了其他一些属性，这些属性是添加了行为后才有的。更改speed速度为80（单位：像素/秒） 
同样的方法给Bullet子弹对象的速度更改为400，Explosion对象的Fade行为的Fade out time淡出时间为0.5秒。

        ![](https://www.scirra.com/images/articles/bulletproperties.png)
    
    - 按住CTRL，拖拽Monster对象,将他们复制7到8个，以充实我们的敌人数量。

- 第三步 添加游戏事件
    - 在event sheet的空白位置双击，将打开添加事件对话框。此过程我们将添加许多事件，在此就不一一赘述，有愿意的朋友可以寻找网络教程。下面给出我的事件列表做一个示范。

        ![](http://a3.qpic.cn/psb?/V1186OFx1RNIby/2lLrE43dBBJj*gp0g2jQASjLbcChG5D1hvI2Mbhg9iI!/m/dFoAAAAAAAAAnull&bo=QwKJAgAAAAADB.g!&rf=photolist&t=5)

##### CRC卡片        
    
        | Object Name    | player                                  |
        
        | Attributes     | (372, 240)                              |

        | Collaborator   | Sprite                                  |
        
        |Events & Actions| 8Direction & ScrollTo & BoundToLayout   |
        
        | Object Name    | monster                                |
        
        |   Attributes     | (random)                                |
        
        | Collaborator   | Sprite                                  |
        
        |Events & Actions| BoundToLayout & Bullet                  |
        
        | Object Name    | Bullet                                  |
        
        | Attributes     | (舞台外)                                 |
        
        | Collaborator   | Sprite                                  |
        
        |Events & Actions| DestroyOutsideLayout & 碰撞并销毁自己    |
        
### 3.开始游戏

    - 点击运行图标，享受自己制作的小游戏吧~

![](https://img01.sogoucdn.com/net/a/04/link?url=https%3A%2F%2Fimg03.sogoucdn.com%2Fapp%2Fa%2F100520093%2Fe18d20c94006dfe0-2857e2f09ca9e0a0-f60d384c0f32915091b75eb0964f1112.jpg&appid=122)

### 4.本人作品欣赏

![](images\动图.gif)










    


        



