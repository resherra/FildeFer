# Fil de Fer

A wireframe modeling program built with C and a mini graphics library ([minilibx](https://github.com/42Paris/minilibx-linux)).

## Screenshots

![App Screenshot](https://github.com/resherra/FildeFer/blob/master/Screen%20Shot%202024-04-27%20at%206.15.51%20PM.png)

```
./fdf maps/t2.fdf
```

| control                     | Description                          |
| :-------------------------- | :----------------------------------- |
| x, y, z or mouse            | rotate around their respective axes. |
| left & scroll buttons, f, g | translate, zoom in & out             |

If you want to run this on your machine:

- **MODE** macro in `fdf.h` should be set to `0` for **macOS**, and to any other value for **Linux**.
- Make sure to adjust the `FRAMEWORK` variable in the **Makefile** according to your platform.
