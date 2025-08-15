# Click Game

A simple and fun Qt-based desktop game where players need to click a moving button as many times as possible within a 30-second time limit.

## Features

- **Moving Target**: The button randomly moves to different positions after each click
- **Timer**: 30-second countdown timer
- **Score Tracking**: Keeps track of how many successful clicks you make
- **Game Over Screen**: Shows your final score when time runs out
- **Cross-Platform**: Built with Qt for Windows, macOS, and Linux compatibility

## Screenshots

The game features a clean interface with a moving "Click me" button and a timer display at the top.

## Requirements

### Build Requirements
- **CMake** 3.16 or higher
- **Qt** 5 or 6 with Widgets module
- **C++17** compatible compiler
- **Git** (for cloning the repository)

### Supported Platforms
- Windows
- macOS
- Linux

## Installation & Building

### 1. Clone the Repository
```bash
git clone <repository-url>
cd <repository-name>
```

### 2. Install Qt
- **Ubuntu/Debian**: `sudo apt-get install qt6-base-dev`
- **Fedora**: `sudo dnf install qt6-qtbase-devel`
- **macOS**: `brew install qt6`
- **Windows**: Download from [Qt official website](https://www.qt.io/download)

### 3. Build the Project
```bash
mkdir build
cd build
cmake ..
make
```

### 4. Run the Game
```bash
./test
```

## How to Play

1. **Start**: Launch the application and click the "Start" button
2. **Click**: Click the "Click me" button as many times as possible
3. **Timer**: You have 30 seconds to score as many points as you can
4. **Challenge**: The button moves to a random position after each successful click
5. **Game Over**: When time runs out, your final score will be displayed

## Project Structure

```
├── src/
│   ├── headers/           # Header files
│   │   ├── mainwindow.h
│   │   ├── gamewindow.h
│   │   └── gameoverwindow.h
│   ├── source/            # Source files
│   │   ├── main.cpp
│   │   ├── mainwindow.cpp
│   │   ├── gamewindow.cpp
│   │   └── gameoverwindow.cpp
│   └── forms/             # UI forms
│       └── mainwindow.ui
├── images/                # Game assets
│   └── backgroung.jpg
├── resources.qrc          # Qt resource file
├── CMakeLists.txt         # Build configuration
└── README.md             # This file
```

## Technical Details

- **Framework**: Qt Widgets
- **Language**: C++17
- **Build System**: CMake
- **Architecture**: Model-View-Controller pattern with Qt signals/slots
- **Timer**: Uses QTimer with 1-second intervals
- **Random Movement**: QRandomGenerator for button positioning

## Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## License

This project is open source. Please check the license file for more details.

## Development

### Adding New Features
- New game modes can be added by extending the `gamewindow` class
- UI modifications can be made through Qt Designer or by editing the `.ui` files
- Additional resources can be added to `resources.qrc`

### Known Issues
- Window resizing during gameplay may affect button positioning
- Score is not persistent between game sessions

## Contact

For questions, suggestions, or bug reports, please open an issue in the repository.

---

**Have fun clicking!** 🎯