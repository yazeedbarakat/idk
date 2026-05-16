from pydantic import BaseModel, Field, model_validator, ValidationError
from datetime import datetime
from enum import Enum


class Rank(Enum):
    cadet = "cadet"
    officer = "officer"
    lieutenant = "lieutenant"
    captain = "captain"
    commander = "commander"


class CrewMember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = "planned"
    budget_millions: float = Field(ge=1, le=10000)

    @model_validator(mode='after')
    def validator(self) -> 'SpaceMission':
        if self.mission_id[0] != 'M':
            raise ValueError("Mission ID must start with 'M'")
        ranks = [r.rank for r in self.crew]
        if Rank.commander not in ranks and Rank.captain not in ranks:
            raise ValueError("Mission must have at least one ",
                             "Commander or Captain")
        if self.duration_days > 365:
            experienced = [e for e in self.crew if e.years_experience >= 5]
            if len(experienced) < len(self.crew) * 0.5:
                raise ValueError("Long missions need 50% ",
                                 "experienced crew (5+ years)")
        if not all(m.is_active for m in self.crew):
            raise ValueError("All crew members must be active")
        return self


def main() -> None:
    print("Space Mission Crew Validation")
    print("=========================================")
    print("Valid mission created:")
    sarah = CrewMember(
        member_id="cm1",
        name="Sarah Connor",
        rank="commander",
        age=30,
        specialization="Mission Command",
        years_experience=10,
    )
    john = CrewMember(
        member_id="cm2",
        name="John Smith",
        rank="lieutenant",
        age=30,
        specialization="Navigation",
        years_experience=10,
    )
    alice = CrewMember(
        member_id="cm3",
        name="Alice Johnson",
        rank="officer",
        age=30,
        specialization="Engineering",
        years_experience=10,
    )
    mission = SpaceMission(
        mission_id="M2024_MARS",
        mission_name="Mars Colony Establishment",
        destination="Mars",
        duration_days=900,
        budget_millions=2500,
        crew=[sarah, john, alice],
        launch_date=datetime.now()
    )
    print("Mission ", mission.mission_name)
    print("ID: ", mission.mission_id)
    print("Destination: ", mission.destination)
    print("Duration: ", mission.duration_days)
    print("Budget: ", mission.budget_millions)
    print("Crew size: ", len(mission.crew))
    print("Crew members:")
    for i in mission.crew:
        print(f"- {i.name} ({i.rank.value}) - {i.specialization}")
    print("\n=========================================")
    print("Expected validation error:")
    ronaldo = CrewMember(
        member_id="cm4",
        name="Cristiano Ronaldo",
        rank="cadet",
        age=30,
        specialization="Engineering",
        years_experience=10,
    )
    try:
        SpaceMission(
            mission_id="M2024_MARS",
            mission_name="Mars Colony Establishment",
            destination="Mars",
            duration_days=900,
            budget_millions=2500,
            crew=[ronaldo, john, alice],
            launch_date=datetime.now()
        )
    except ValidationError as e:
        print(e)


if __name__ == "__main__":
    main()
