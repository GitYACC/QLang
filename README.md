# QLang

```c
namespace Struct {
    public static cashapp = 0

    private def func(something) {
        print(something)
    }

    noninherit class StructVoider(struct) {
        constructor(name) {
            super.name = name
            self.name2 = name
        }

        infix +++(other: String, sumn) {
            super.name += other
        }

        ternary cond ! other : other2 {
            if not cond {
                return other
            } else {
                return other2
            }
        }
    }

    private mylist = []
}
```
