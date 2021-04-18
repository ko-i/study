fn move_coords(x: (i32, i32)) -> (i32, i32) {
    (x.0 + 1, x.1 + 1)
}

fn main() {
    let tuple: (&'static str, i32, char) = ("hello", 5, 'c');
    assert_eq!("hello", tuple.0);
    assert_eq!(5, tuple.1);
    assert_eq!('c', tuple.2);

    let coords = (0, 1);
    let result = move_coords(coords);
    assert_eq!((1, 2), result);

    let (x, y) = move_coords(coords);
    assert_eq!(1, x);
    assert_eq!(2, y);
}