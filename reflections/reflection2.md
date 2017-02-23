# Reflection 2

## Written Reflection

While my team was stuck in a rut for a while, we did somehow end up completing a stretch goal by the end of the sprint. Our progress aligns well with my personal goals, since I got to learn fairly in depth about servers and clients in C. During the sprint, we did a lot of full group programming (which actually went really well). Our debugging process was revised part way through. At first we went as a group, since we figured that the bug would be simple to fix and that everyone would learn from the correction. The bug was not simple to figure out how to fix. Eventually, we decided it would be better to each work concurrently, yet that also took a while. When two of us sat down together to try something after the individual time, we fixed it almost immediately (turns out it was a two step fix, for which two of us were doing one of the steps). Because of that process, we've decided to debug in pairs.

## Completed Readings/Exercises

- [Head First C Chapter 3](https://github.com/jsutker/ExercisesInC/tree/master/exercises/ex03)
- [Head First C Chapter 4](https://github.com/jsutker/ExercisesInC/tree/master/exercises/ex04)
- [Think OS Chapter 3](https://github.com/jsutker/ExercisesInC/tree/master/reading_questions)
- [Think OS Chapter 4](https://github.com/jsutker/ExercisesInC/tree/master/reading_questions)

## Exam question

### Q: Describe the 6 different basic data types

#### A: A `char` stores a character that the computer interprets as a certain integer (i.e., if it's stored as `65`, it's the same as it being stored as `'A'`). An `int` stores an integer in at least 16 bits. A `short` stores an integer in approximately half the bits of an `int`. A `long` stores an integer in at least 32 bits, but they're often the same size as `int`, since they can be up to that. A `float` stores a floating-point number. A `double` stores a floating-point number in twice as many bits as a `float`, so as to add more precision.