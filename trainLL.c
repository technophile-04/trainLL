#include <stdio.h>
#include <stdlib.h>

enum class
{
    Sleeper,
    AC1,
    AC2,
    AC3
};

struct Train
{
    int id;
    int bogie[12];
    int maxSeats;
};

struct Passenger
{
    char *name;
    int id;
    char *trainName;
    char *borardingStation;
    enum class classType;
    char *destinationStation;
    int trainID;
    int seatNo;
    int isUpgradble;
    struct Passenger *next;
    struct Train *train;
};

struct Passenger *createPassenger(
    int id,
    char *trainName,
    char *borardingStation,
    enum class c,
    char *destinationStation,
    int trainID,
    int seatNo,
    int isUpgradble,
    struct Train *train)
{

    struct Passenger *newPassenger = (struct Passenger *)malloc(sizeof(struct Passenger));
    newPassenger->id = id;
    newPassenger->trainName = trainName;
    newPassenger->borardingStation = borardingStation;
    newPassenger->classType = c;
    newPassenger->destinationStation = destinationStation;
    newPassenger->trainID = trainID;
    newPassenger->seatNo = seatNo;
    newPassenger->isUpgradble = isUpgradble;
    newPassenger->train = train;
    newPassenger->next = NULL;
    return newPassenger;
}

struct Passanger *insertPassanger(struct Passenger *head, int id,
                                  char *trainName,
                                  char *borardingStation,
                                  enum class c,
                                  char *destinationStation,
                                  int trainID,
                                  int seatNo,
                                  int isUpgradble,
                                  struct Train *train)
{
    struct Passenger *newPassenger = createPassenger(id, trainName, borardingStation, c, destinationStation, trainID, seatNo, isUpgradble, train);

    struct Passenger *prev, *next;

    if (!head)
    {
        head = newPassenger;
    }
    else
    {
        prev = NULL;
        next = head;
        while (next && next->trainID <= trainID)
        {
            prev = next;
            next = next->next;
        }
        if (!next)
        {
            prev->next = newPassenger;
        }
        else
        {
            if (prev)
            {
                newPassenger->next = prev->next;
                prev->next = newPassenger;
            }
            else
            {
                newPassenger->next = head;
                head = newPassenger;
            }
        }
    }
    return head;
}

struct Passenger *createList(struct Passenger *passengers, int noOfPassengers, struct Train *trains, int noOfTrains)
{

    struct Passenger *head = NULL;

    for (int i = 0; i < noOfPassengers; i++)
    {

        int trainId = passengers[i].trainID;
        enum class c = passengers[i].classType;

        switch (c)
        {
        case 0:
            int isAllocated = 0;
            for (int j = 0; j < 2; j++)
            {
                if (trains[trainId].bogie[j] <= trains[trainId].maxSeats)
                {
                    trains[trainId].bogie[j]++;
                    head = insertPassanger(head, passengers[i].id, passengers[i].trainName, passengers[i].borardingStation, passengers[i].classType, passengers[i].destinationStation, passengers[i].trainID, trains[trainId].bogie[j], passengers[i].isUpgradble, &trains[trainId]);
                    isAllocated = 1;
                    break;
                }
            }

            if (!isAllocated)
            {
                printf("%s could not be allocated seat\n", passengers[i].name);
            }
            else
            {
                printf("%s seat allocated successfull\n", passengers[i].name);
            }
            break;

        case 1:
            int isAllocated = 0;
            for (int j = 2; j < 4; j++)
            {
                if (trains[trainId].bogie[j] <= trains[trainId].maxSeats)
                {
                    trains[trainId].bogie[j]++;
                    head = insertPassanger(head, passengers[i].id, passengers[i].trainName, passengers[i].borardingStation, passengers[i].classType, passengers[i].destinationStation, passengers[i].trainID, trains[trainId].bogie[j], passengers[i].isUpgradble, &trains[trainId]);
                    isAllocated = 1;
                    break;
                }
            }

            if (!isAllocated)
            {
                printf("%s could not be allocated seat\n", passengers[i].name);
            }
            else
            {
                printf("%s seat allocated successfull\n", passengers[i].name);
            }
            break;
        case 2:
            int isAllocated = 0;
            for (int j = 4; j < 6; j++)
            {
                if (trains[trainId].bogie[j] <= trains[trainId].maxSeats)
                {
                    trains[trainId].bogie[j]++;
                    head = insertPassanger(head, passengers[i].id, passengers[i].trainName, passengers[i].borardingStation, passengers[i].classType, passengers[i].destinationStation, passengers[i].trainID, trains[trainId].bogie[j], passengers[i].isUpgradble, &trains[trainId]);
                    isAllocated = 1;
                    break;
                }
            }

            if (!isAllocated)
            {
                printf("%s could not be allocated seat\n", passengers[i].name);
            }
            else
            {
                printf("%s seat allocated successfull\n", passengers[i].name);
            }
            break;
        case 3:
            int isAllocated = 0;
            for (int j = 6; j < 12; j++)
            {
                if (trains[trainId].bogie[j] <= trains[trainId].maxSeats)
                {
                    trains[trainId].bogie[j]++;
                    head = insertPassanger(head, passengers[i].id, passengers[i].trainName, passengers[i].borardingStation, passengers[i].classType, passengers[i].destinationStation, passengers[i].trainID, trains[trainId].bogie[j], passengers[i].isUpgradble, &trains[trainId]);
                    isAllocated = 1;
                    break;
                }
            }

            if (!isAllocated)
            {
                printf("%s could not be allocated seat\n", passengers[i].name);
            }
            else
            {
                printf("%s seat allocated successfull\n", passengers[i].name);
            }
            break;

        default:
            break;
        }
    }

    return head;
}

void printList(struct Passenger *head)
{
    struct Passenger *temp = head;
    while (temp != NULL)
    {
        printf("%d name\n", temp->id);
        printf("%s name\n", temp->name);
        printf("%s trainName\n", temp->trainName);
        printf("%s boardingStation\n", temp->borardingStation);
        printf("------------\n");
        temp = temp->next;
    }

    return;
}

int main()
{
    int noOfTrains;
    enum class classType;
    scanf("%d", &noOfTrains);
    struct Train *trains = malloc(sizeof(struct Train) * noOfTrains);
    struct Passenger *passengers = malloc(sizeof(struct Passenger) * 1);
    passengers[0].name = "Rahul";
    passengers[0].id = 0;
    passengers[0].trainName = "CSMT";
    passengers[0].borardingStation = "Thane";
    passengers[0].classType = 0;
    passengers[0].trainID = 1;
    passengers[0].isUpgradble = 0;
    passengers[0].train = &trains[1];

    for (int i = 0; i < noOfTrains; i++)
    {
        struct Train t1;
        int maxSeats;
        printf("Enter max seats in train number %d");
        scanf("%d", &maxSeats);

        t1.id = i;
        t1.maxSeats = maxSeats;
        for (int j = 0; j < 12; i++)
        {
            t1.bogie[j] = 0;
        }

        trains[i] = t1;
    }

    struct Passenger *head = createList(passengers, 1, trains, noOfTrains);

    return 0;
}