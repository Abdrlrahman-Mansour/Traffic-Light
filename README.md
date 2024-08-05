# Traffic Light System

This project simulates a traffic light system using a PIC18F4620 microcontroller. The system mimics the functioning of a real-world traffic light, controlling the flow of vehicles at an intersection. The goal is to provide a practical example of microcontroller-based control systems and their applications in everyday life.

## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [Hardware Components](#hardware-components)
4. [Software Requirements](#software-requirements)
5. [System Design](#system-design)
6. [Getting Started](#getting-started)
   - [Prerequisites](#prerequisites)
   - [Installation](#installation)
   - [Usage](#usage)
7. [Troubleshooting](#troubleshooting)
8. [Future Enhancements](#future-enhancements)
9. [Contributing](#contributing)
10. [License](#license)
11. [Acknowledgements](#acknowledgements)

## Introduction

Traffic lights are essential for managing traffic flow and ensuring safety at intersections. This project demonstrates a basic traffic light control system, which can be used as an educational tool for learning about embedded systems, control logic, and real-time applications.

## Features

- **Red, Yellow, and Green Lights:** Controlled timing for each light to simulate real traffic signals.
- **Pedestrian Crossing:** An optional feature to simulate pedestrian signals.
- **Emergency Mode:** Special mode for emergency vehicles, allowing them to override regular traffic signals.
- **Modular and Expandable Design:** Easy to add more features or integrate with other systems.

## Hardware Components

- **Microcontroller:** PIC18F4620
- **LEDs:** Red, yellow, and green LEDs to represent traffic lights.
- **Resistors:** To limit the current for LEDs.
- **Breadboard and Jumper Wires:** For connecting components.
- **Power Supply:** 5V regulated power supply for the circuit.


## Software Requirements

- **MPLAB X IDE:** Integrated Development Environment for Microchip microcontrollers.
- **XC8 Compiler:** Compiler for PIC microcontrollers.
- **Proteus 8.9 Professional** : To simulate the circuit. 


## System Design

The system consists of a microcontroller controlling three sets of LEDs, each representing a traffic signal light. The timing for each light is controlled using timers within the microcontroller. The design also includes provisions for pedestrian crossings and emergency modes, which can be triggered using additional input mechanisms like push buttons.



## Getting Started

### Prerequisites

- Basic knowledge of microcontrollers and embedded systems.
- Understanding of C programming language.
- Familiarity with MPLAB X IDE and XC8 Compiler.

### Installation

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/Abdrlrahman-Mansour/Traffic-Light.git
   cd Traffic-Light
