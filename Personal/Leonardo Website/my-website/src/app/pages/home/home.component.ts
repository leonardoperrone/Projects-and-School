import { Component, OnInit } from '@angular/core';
import { TechnologyService } from '../../services/technology.service';
import { Observable } from 'rxjs';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.scss', '../../app.component.scss']
})
export class HomeComponent implements OnInit {

  public technologies: Technology[];
  public loaded =  false;
  constructor(private technologyService: TechnologyService) {
  }

  ngOnInit() {
    this.technologyService.getTechnologies().subscribe((res) => {
      this.technologies = res;
      this.loaded = true;
    });
  }

}
