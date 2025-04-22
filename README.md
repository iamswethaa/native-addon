# Node.js Native Addon: Addition Function (N-API with node_api.h)

This project demonstrates how to use N-API with node_api.h to call a C function (addition) from JavaScript.

## Project Structure
```
  native-addon/
  ├── addon.c
  ├── binding.gyp
  ├── index.js
  ├── package.json
  ├── package-lock.json
  └── README.md
```

## Description

- **addon.c :** N-API wrapper that contains the native C function int add(int a, int b) and bridges add() to JavaScript.

- **index.js :** JavaScript file that uses the native addon.

- **binding.gyp :** Build configuration for node-gyp.

## Build Instructions

### 1. Install node-gyp if not already installed

```bash
npm install -g node-gyp
```

### 2. Initialize and build the addon

```bash
npm install
node-gyp configure
node-gyp build
```

The compiled addon will be created in the build/Release/ folder.

## Run Script

```bash
node index.js
```
