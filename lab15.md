## 智能贪吃蛇

上周在写过字符贪吃蛇后，这周又有了新的任务，制作一条智能蛇。智能蛇与字符蛇不同的地方在于，要让蛇自己判断如何选择避免身体和墙壁，以及选择能够吃到食物的最优途径。这些都需要用代码来实现，在判断完如何进行下一步后，返回程序下一步蛇要走的方向，这样，蛇就能够无忧无虑地吃得更长，我们的程序也就完成了。

毫无疑问，判断蛇行走方向的函数是程序的精髓所在，老师列出了方向函数的伪代码，我们根据伪代码的结构写出判断蛇行走方向的函数wheregonext是重中之重。

#### 决定蛇行走的方向函数的伪代码

```c
// Hx,Hy: 头的位置
    // Fx,Fy：食物的位置
	function whereGoNext(Hx,Hy,Fx,Fy) {
	// 用数组movable[3]={“a”,”d”,”w”,”s”} 记录可走的方向
	// 用数组distance[3]={0,0,0,0} 记录离食物的距离
	// 分别计算蛇头周边四个位置到食物的距离。H头的位置，F食物位置
	//     例如：假设输入”a” 则distance[0] = |Fx – (Hx-1)| + |Fy – Hy|
	//           如果 Hx-1，Hy 位置不是Blank，则 distance[0] = 9999
	// 选择distance中存最小距离的下标p，注意最小距离不能是9999
	// 返回 movable[p]
	}
```
    下面是我写出的wheregonext函数的代码：

```c

    char wheregonext(int hx, int hy, int fx, int fy) {// Hx,Hy: 头的横纵坐标 
    // Fx,Fy：食物的横纵坐标 
    int p = 0, min = 9999;
    distance[0] = abs(fx - (hx - 1)) + abs(fy - hy);//这里我们使用abs函数直接得出距离的绝对值 
    distance[1] = abs(fx - (hx + 1)) + abs(fy - hy);
    distance[2] = abs(fx - hx) + abs(fy - (hy - 1));
    distance[3] = abs(fx - hx) + abs(fy - (hy + 1));
    // 比较蛇头四个周边位置到食物的距离 
    if (distance[0] <= min && (map[hy][hx - 1] == ' ' || map[hy][hx - 1] == '$')) {
            min = distance[0];
            p = 0;
        }
    if (distance[1] <= min && (map[hy][hx + 1] == ' ' || map[hy][hx + 1] == '$')) {
            min = distance[1];
            p = 1;
        }
    if (distance[2] <= min && (map[hy - 1][hx] == ' ' || map[hy - 1][hx] == '$')) {
            min = distance[2];
            p = 2;
        }
    if (distance[3] <= min && (map[hy + 1][hx] == ' ' || map[hy + 1][hx] == '$')) {
            min = distance[3];
            p = 3;
        }
    // 选择distance中存最小距离的下标p，最小距离不能是9999
    min = 9999;
    return movable[p];  // 返回 movable[p]
}
```

这样，我们就完成了智能蛇代码中较为重要的返回方向的函数。另外，根据方向命令蛇移动的函数也是贪吃蛇中非常重要的环节，还好这个问题在上周已经解决过，所以经过一番组合修改，终于可以得到智能蛇运行的主程序啦：

```c
int main() {
    int i;
    snakefood();
    printmap();
    //打印初始状态图
    char c;
   int a = 0, b = 0;
    while (1)
    {
        snakefood();
        c = wheregonext(snakex[0], snakey[0], x, y);
        Sleep(250);
        switch (c){//进行移动
        case 'a'://左移时
            a = 1;
            b = 0;
			snakefood();
            move(a, b);
            if (gameover())//判断游戏是否结束
            {
                printf("\nGAME OVER!!!\n");
                Sleep(1000);
                return 0;
            }
            else
            {
                system("cls");
                printmap();
            }
            break;
        case 'd'://右移
            b = 1;
            a = 0;
            snakefood();
            move(a, b);
            if (gameover())//判断游戏是否结束
            {
                printf("\nGAME OVER!!!\n");
                Sleep(1000);
                return 0;
            }
            else
            {
                system("cls");
                printmap();
            }
            break;
        case 's'://上移
            a = -1;
            b = 0;
            snakefood();
            move(a, b);

            if (gameover())//判断游戏是否结束
            {
                printf("\nGAME OVER!!!\n");
                Sleep(1000);
                return 0;
            }
            else
            {
                system("cls");
                printmap();
            }
            break;
        case 'w'://下移
            b = -1;
            a = 0;
            snakefood();
            move(a, b);
            if (gameover())//判断游戏是否结束
            {
                printf("\nGAME OVER!!!\n");
                Sleep(1000);
                return 0;
            }
            else
            {
                system("cls");
                printmap();
            }

            break;
        }

    }

}
```

上面的主函数中我们使用了<Windows.h>库里面的Sllep函数，Sllep函数的功能是可以让程序在下次操作前停顿一会，Sleep中的传入值以毫秒为单位，我用了250这个数值（忽略它的其他含义），可以让我们比较舒服地观看蛇蛇是如何茁壮成长的。

下面是智能蛇的运行，我们看一下吧：

![](http://a1.qpic.cn/psb?/V1186OFx1RNIby/BTXbhEHCGm1nAGn.kKzDAi8*yYtAS4sjkhz3CI3Tmeo!/m/dLwAAAAAAAAAnull&bo=NAEXAQAAAAACBwA!&rf=photolist&t=5)

### 总结

这次的智能蛇只写了不到300行，网上有大佬可以写出1000行的超级智能蛇算法（瑟瑟发抖）。我们的智能蛇在运行过一段时间后就会被自己憋死，而进阶的算法的精髓在于，让贪吃蛇的蛇头沿着蛇尾移动，这样便不是最短路径，而是最长路径，这样的贪吃蛇就可以一直吃到充满整个地图，十分壮观。

关于智能蛇的算法还有许多可以优化的地步，准确地说关于贪吃蛇的代码，我们还有很多需要学习的地方，经过优化后的贪吃蛇肯定可以运行更久，希望今后自己通过学习可以达到这样的水平，让我们继续加油吧。 

共勉~

![](http://m.qpic.cn/psb?/V1186OFx1RNIby/85VqRiaG5coQQCATBzGrqcJSnUyjQHlF*D.KkTTZJwk!/b/dLgAAAAAAAAA&bo=pgGkAQAAAAARBzI!&rf=viewer_4) 




