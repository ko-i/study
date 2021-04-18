struct Foo<'a> {
    part: &'a str,
}

fn main() {
    let words = String::from("Sometimes think, the greater sorrow than older");
    let first = words.split(',').next().expect("Could not find a ','");

    let f = Foo {
        part: first,
    };

    assert_eq!("Sometimes think", f.part);
}