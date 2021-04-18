trait Page {
    fn set_page(&self, p: i32) {
        println!("Page default: {}", p);
    }
}

trait PerPage {
    fn set_perpage(&self, num: i32) {
        println!("Per Page Default: {}", num);
    }
}

trait Paginate: Page + PerPage {
    fn set_skip_page(&self, num: i32) {
        println!("Skip page: {}", num);
    }
}

impl <T: Page + PerPage>Paginate for T {}

struct MyPaginate {
    page: i32,
}

impl PerPage for MyPaginate{}
impl Page for MyPaginate {}

fn main() {
    let my_paginate = MyPaginate {page: 1};
    my_paginate.set_page(2);
    my_paginate.set_perpage(100);
    my_paginate.set_skip_page(12);
}