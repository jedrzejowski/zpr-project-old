//
// Created by adam on 06.05.18.
//

#pragma once


class PerlinNoise {
private:

	double Total(double i, double j) const;
	double GetValue(double x, double y) const;
	double Interpolate(double x, double y, double a) const;
	double Noise(int x, int y) const;

	double persistence, frequency, amplitude;
	int octaves, randomseed;
public:

	// Constructor
	PerlinNoise();
	PerlinNoise(double _persistence, double _frequency,
				double _amplitude, int _octaves, int _randomseed);

	// Get Height
	double GetHeight(double x, double y) const;

	// Get
	double GetPersistence() const;
	double GetFrequency() const;
	double GetAmplitude() const;
	int GetOctaves() const;
	int GetRandomSeed() const;

	// Set
	void Set(double _persistence, double _frequency, double _amplitude, int _octaves, int _randomseed);

	void SetPersistence(double _persistence);
	void SetFrequency(double _frequency);
	void SetAmplitude(double _amplitude);
	void SetOctaves(int _octaves);
	void SetRandomSeed(int _randomseed);
};

