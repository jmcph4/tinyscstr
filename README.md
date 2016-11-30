# tinyscstr #
---

The **t**iny **s**afe **C** **str**ing library. Strings are immutable at this stage (by that I mean concatenation doesn't modify supplied strings).

Basically, we have `scstr` type which just tracks size (*including terminating `NUL` byte*) and contents of the string, with some memory management abstractions on top.
