package com.tsoy.backend.utils;

import com.github.javafaker.Faker;
import com.tsoy.backend.entity.Bike;
import com.tsoy.backend.repository.BikeRepository;

import org.springframework.boot.CommandLineRunner;
import org.springframework.stereotype.Component;

import java.util.Arrays;
import java.util.List;
import java.util.Locale;

@Component
public class DataGenerator implements CommandLineRunner {

    private final BikeRepository bikeRepository;
    private final Faker faker = new Faker(new Locale("ru"));

    public DataGenerator(BikeRepository bikeRepository) {
        this.bikeRepository = bikeRepository;
    }
    
    @Override
    public void run(String... args) {
        if (bikeRepository.count() == 0) {
            List<Bike> bikes = Arrays.asList(
                createFakeBike(),
                createFakeBike(),
                createFakeBike()
            );
            bikeRepository.saveAll(bikes);
        }
    }

    private Bike createFakeBike() {
        String[] colors = {"white", "black", "red", "blue", "green", "orange"};
        String[] brands = {"Stark", "Stark Industries", "BikeMaster", "Velorace", "Speedster"};

        return new Bike(
            null,
            "https://cdn.velostrana.ru/upload/models/velo/63860/small.jpg",
            "Велосипед " + faker.number().numberBetween(1, 100),
            faker.options().nextElement(brands),
            "Отличный велосипед " + faker.lorem().sentence(10),
            Long.valueOf(faker.number().numberBetween(20000, 100000)),
            faker.number().numberBetween(10, 25),
            faker.options().nextElement(colors)
        );
    }
}