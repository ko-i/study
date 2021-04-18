use std::thread;

struct City {
    name: String,
    population: i64,
    country: String,
}

fn city_population_descending(city: &City) -> i64 {
    -city.population
}

fn sort_cities_1(cities: &mut Vec<City>) {
    cities.sort();
}

fn sort_cities_2(cities: &mut Vec<City>) {
    cities.sort_by_key(city_population_descending);
}

fn sort_cities_3(cities: &mut Vec<City>) {
    cities.sort_by_key(|city| -city.population);
}

fn sort_by_statistic(cities: &mut Vec<City>, stat: Statistic) {
    cities.sort_by_key(|city| -city.get_statistic(stat));
}

fn start_sorting_thread_1(mut cities: Vec<City>, stat: Statistic) -> thread::JoinHandle<Vec<City>> {
    let key_fn = |city: &City| -> i64 {
        -city.get_statistic(stat)
    };

    thread::spawn(|| {
        cities.sort_by_key(key_fn);

        cities
    })
}

fn start_sorting_thread_2(mut cities: Vec<City>, stat: Statistic) -> thread::JoinHandle<Vec<City>> {
    let key_fn = move |city: &City| {
        -city.get_statistic(stat)
    };

    thread::spawn(move || {
        cities.sort_by_key(key_fn);

        cities
    })
}

fn count_selected_cities_1(cities: &Vec<City>, test_fn: fn(&City) -> bool) -> usize {
    let mut count = 0;

    for city in cities {
        if test_fn(city) {
            count += 1;
        }
    }

    count
}

fn count_selected_cities_2<F>(cities: &Vec<City>, test_fn: F) -> usize where F: Fn(&City) -> bool {
    let mut count = 0;

    for city in cities {
        if test_fn(city) {
            count += 1;
        }
    }

    count
}

fn has_monster_attacks(city: &City) -> bool {
    city.monster_attack_risk > 0.0
}

fn main() {
    let my_key_fn: fn(&City) -> i64 = 
        if user.prefs.by_population {
            city_population_descending
        } else {
            city_monster_attack_risk_descending
        };

    cities.sort_by_key(my_key_fn);

    let n = count_selected_cities_1(&my_cities, has_monster_attacks);

    let limit = preferences.acceptable_monster_risk();
    let n = count_selected_cities_2(&my_cities, |city| city.monster_attack_risk > limit);
}