# philosophers
make && ./philo arg1 arg2 arg3 arg4 arg5


[Youtube playlist about threads were I learned from](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)


[Youtube video about breaking down the problem](https://www.youtube.com/watch?v=NbwbQQB7xNQ)


[Another youtube video about breaking down the problem](https://www.youtube.com/watch?v=dOVdsd31WNg)


[Inspired from](https://github.com/iciamyplant/Philosophers)


# Get familiar with the subject
- chaque philosophe est un **thread**, et chaque fourchette est un **mutex**
- ils font dans l'ordre : manger - dormir - penser (ils pensent pas vraiment, ils attendent d'avoir leurs fourchettes pour manger)
- pour manger ils doivent avoir deux fourchettes, sachant que y a que une fourchette par philosophe
- si y en a un qui meurt la simulation s'arrête et on doit afficher la mort dans maximum 10 millisecondes
- ecrire chaque changement de statut de philosophe

./philo arg1 arg2 arg3 arg4 arg5

- arg1 = number_of_philosophers (nombre de philosophes et nombre de fourchettes)
- arg2 = time_to_die (s’il a pas mangé depuis time_to_die millisecondes il meurt)
- arg3 = time_to_eat (temps pour manger avec deux fourchettes en millisecondes)
- arg4 = time_to_sleep (temps pour dormir en milliseconde)
- arg5 = number_of_times_each_philosopher_must_eat (nombre de fois que chaque philosophe doit manger, arg optionnel)

# Strategy

- Faire partir les philos pairs ou impairs avec du retard. Car si tous les philosophes commencent en meme temps et prennent leur fourchette droite personne ne pourra manger.
```
	if (ph->id % 2 == 0)
		ft_usleep(ph->pa->eat / 10);
```

- Chaque philosophe a sa propre fourchette à gauche (l_f) et emprunte celle de son voisin a droite grace au pointeur (\*r_f) qui pointe sur la l_f du voisin de droite :

```
while (i < p->a.total)
{
	p->ph[i].id = i + 1;
	pthread_mutex_init(&p->ph[i].l_f, NULL);  // chaque philosopher detient sa propre fourchette a gauche
	if (i == p->a.total - 1)
		p->ph[i].r_f = &p->ph[0].l_f;           // et emprunte celle de son voisin de droite
	else
		p->ph[i].r_f = &p->ph[i + 1].l_f;       // et emprunte celle de son voisin de droite
	i++;
}
```

- Obligee de checker la mort dans un thread a cote sinon ne se rend pas compte a temps si y en a un qui meurt. Mais par contre si le thread check en continue la si le philo est mort ca baisse trop les perfs. Donc a chaque fois qu'un philo va faire ses activites un thread qui check la mort se lance. Et ce thread va usleep(time_to_die) et ensuite checker si le philo est mort. 

```
pthread_create(&ph->thread_death_id, NULL, is_dead, data);
void	*is_dead(void	*data)
{
	ft_usleep(ph->pa->die + 1);
	if (!check_death(ph, 0) && !ph->finish && ((actual_time() - ph->ms_eat) \
		>= (long)(ph->pa->die)))
		le philo est mort
```

# Handeling time

| seconde | milliseconde | microseconde |
|----------|-------|-------|
| 1 | 1000 | 1e+6 |
| 0,001 | 1 | 1000 |

- Fonctionnement de gettimeofday :
```
   struct timeval current_time;
   gettimeofday(&current_time, NULL);
   printf("seconds : %ld\nmicro seconds : %d", current_time.tv_sec, current_time.tv_usec);
```

- Pour connaitre le temps actuel en millisecondes avec gettimeofday :
```
long int		actual_time(void)
{
	long int			time;
	struct timeval		current_time;
	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		ft_exit("Gettimeofday returned -1\n");
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000); //temps en millisecondes
	return (time);
}
```

- creer sa propre fonction ft_usleep car la vraie fonction attend au minimum le temps qu'on lui indique, donc pas precis
```
void	ft_usleep(long int time_in_ms)
{
	long int	start_time;
	start_time = 0;
	start_time = actual_time();
	while ((actual_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}
````

