# X游戏设计    

### 1.游戏的策划

#### 游戏名称：

- The war of freedom（自由之战）

#### 楔子：

- 距离上次星球大战不久，身为宇宙帝国侦查兵的Jackey不愿再被奴隶一样使唤。他也有感情，也有家庭，也有自己渴望的生活。于是他拿起武器，反戈一击，用自己的血肉之躯，抵抗残暴的统治者，发起一场自由之战，找回属于他的自由。

#### 玩法：

- 操控Jackey，用自己精妙绝伦的射击技巧和灵动飘逸的身法，击败这些来讨伐你的黑衣人。战胜他们，找回自由！

#### 人设与道具:

- 侦察兵Jackey:掌握精湛射击技巧的他总是弹无虚发，能够与自己的武器“曙光审判”合二为一，人枪一体，发出震慑敌人的光弹。为了找回属于自己的自由，他别无选择的与黑衣人展开了战斗。

- 黑衣人：为了讨伐背叛帝国的Jackey，他们奉命前来了结他的性命，是Jackey归乡途中最大的绊脚石。

### 2.CRC卡片        
    
        | Object Name    | player                                  |
        
        | Attributes     | (372, 240)                              |

        | Collaborator   | Sprite                                  |
        
        |Events & Actions| 8Direction & ScrollTo & BoundToLayout   |
        
        | Object Name    | monster                                 |
        
        | Attributes     | (random)                                |
        
        | Collaborator   | Sprite                                  |
        
        |Events & Actions| BoundToLayout & Bullet                  |
        
        | Object Name    | Bullet                                  |
        
        | Attributes     | (舞台外)                                 |
        
        | Collaborator   | Sprite                                  |
        
        |Events & Actions| DestroyOutsideLayout & 碰撞并销毁自己    |

### 3.本人作品欣赏

![](images\动图.gif)