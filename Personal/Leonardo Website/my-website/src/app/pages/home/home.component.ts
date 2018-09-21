import { Component, OnInit } from '@angular/core';
import { TechnologyService } from '../../services/technology.service';
import { Observable } from 'rxjs';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.scss', '../../app.component.scss']
})
export class HomeComponent implements OnInit {

  public technologies: Observable<Technology[]>;

  constructor(private technologyService: TechnologyService) {
  }

  ngOnInit() {
    this.technologies = this.technologyService.getTechnologies();
  }

}
