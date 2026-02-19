# Doxygen commenting policy (minimal)

This policy defines the minimum Doxygen comments required for the HP2803A project.

Each public header file `*.h` shall begin with:

```c
/**
 * @file
 * @brief <one-line description of the public interface>.
 */
```

Externally visible types (i.e. those exposed in public headers) shall be documented:
```c
/**
 * @brief HP2803A driver instance.
 */
typedef struct
{
    SPI_HandleTypeDef *hspi;  /**< SPI interface used by the device */
} hp2803a_t;
```

Public functions shall be documented with @brief, @param for each parameter, and @return if not void:
```c
/**
 * @brief Initializes the HP2803A driver.
 *
 * @param dev Driver instance.
 * @return 0 on success, negative value on error.
 */
int hp2803a_init(hp2803a_t *dev);
```

Macros that encode hardware semantics or are part of the public API may be documented:
```c
/** HP2803A latch pin active level */
#define HP2803A_LATCH_ACTIVE 1
```
Macros that are purely internal or trivial do not require documentation.

Each source file `*.c` shall begin with:
```c
/**
 * @file
 * @brief <one-line description of the implementation>.
 */
```

Static functions do *not* require documentation unless their behaviour is non-obvious or they encode hardware protocol details:
```c
/**
 * @brief Transfers a raw data frame to the HP2803A via SPI.
 */
static void hp2803a_tx_frame(hp2803a_t *dev, uint32_t frame);
```

Preconditions or invariants should be documented when relevant:
```c
/**
 * @brief Initializes the driver.
 * @note Must be called before any other hp2803a_* function.
 */
```

Units should be documented:
```c
@param timeout_ms Timeout in milliseconds.
```

