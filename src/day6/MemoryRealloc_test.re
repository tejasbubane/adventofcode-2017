open Jest;

let testInput = [|0, 2, 7, 0|];

let myInput = [|10, 3, 15, 10, 5, 15, 5, 15, 9, 2, 5, 8, 5, 2, 3, 6|];

describe(
  "MemoryRealloc - part1",
  () => {
    open Expect;
    test("test", () => expect(MemoryRealloc.solve1(testInput)) |> toBe(5));
    test("myInput", () => expect(MemoryRealloc.solve1(myInput)) |> toBe(14029))
  }
);

describe(
  "MemoryRealloc - part2",
  () => {
    open Expect;
    test("test", () => expect(MemoryRealloc.solve2(testInput)) |> toBe(4));
    test("myInput", () => expect(MemoryRealloc.solve2(myInput)) |> toBe(2765))
  }
);
