# MagicBall - A Console-Based Elimination Game

This repository contains a C++ console application developed as a coursework project at Tongji University. The program implements a matching game, "MagicBall," within a terminal environment using a pseudo-graphical interface.

## Features

**Configurable Grid**: Supports game regions ranging from 5x5 to 9x9 squares.
**Core Mechanics**: Implements elimination logic for three or more consecutive identical balls in a row or column.
**Dynamic Physics**: Includes logic for non-zero item falling, empty space refilling, and score calculation.
**Hint System**: Identifies and highlights adjacent exchangeable items that would result in an elimination.
**Input Support**: Supports both keyboard input and mouse interaction, with specific optimizations to disable console "Quick Edit" mode to prevent execution hangs.

## Technical Implementation

The project is structured with a focus on modularity to reduce redundancy and simplify maintenance. It separates core game logic from hardware-specific terminal controls. 

**State Management**: The application avoids the use of global variables, instead utilizing pointer-based parameter passing to manage game states across functions.
**Rendering**: Uses a custom toolset (`cmd_console_tools`) leveraging Windows API for cursor positioning, color rendering, and event capturing.
**Visual Elements**: Uses solid circles for eliminable balls and hollow double circles for interchangeable hints, with different colors utilized to distinguish ball types.

## Project Structure

*`include/`: Header files defining the game logic and console utilities.
*`src/`: Implementation files including the main entry point, menu systems, and graphical rendering .
*`docs/`: Project documentation and original laboratory reports.

---

# MagicBall - 基于控制台的消除类游戏

本仓库包含一个使用 C++ 开发的控制台应用程序，该项目原为同济大学的一项课程实验 。程序在终端环境下通过伪图形界面实现了一款名为“彩球游戏 (MagicBall)”的消除类游戏 。

## 功能特性

**自定义布局**：支持 5x5 至 9x9 范围内的正方形或长方形游戏区域 。
**核心玩法**：实现了行或列连续三个以上相同数值球体的判定与消除逻辑 。
**动态交互**：包含非零项下落、空位补零、新值填充以及实时分数计算功能 。
**提示系统**：能够自动查找并标记相邻的可互换项（消除提示） 。
**操作支持**：支持键盘与鼠标双重操作，并针对控制台环境禁用了“快速编辑”模式，以确保交互稳定性 。

## 技术实现

项目设计强调模块化分工，旨在减少冗余代码并提升可维护性 。程序将游戏基础逻辑与底层终端控制进行了有效解耦 。

**状态管理**：项目在开发过程中重构了状态管理逻辑，通过指针传递替代全局变量，增强了程序的严谨性 。
**界面渲染**：利用自定义工具库（`cmd_console_tools`）调用 Windows API 实现光标定位、色彩显示及事件捕获 。
**视觉表现**：通过字符符号区分球体状态，如实心圆表示可消除球，空心双圈表示提示球，并辅以背景色区分颜色类别 ]。

## 项目结构

*`include/`: 存放游戏逻辑及控制台工具的头文件 。
*`src/`: 包含程序入口、菜单系统、基础逻辑及图形渲染的实现文件 。
* `docs/`: 存放项目相关的实验报告及留档文档 。
